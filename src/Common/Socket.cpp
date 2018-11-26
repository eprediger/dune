#define _POSIX_C_SOURCE 200112L

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

#include <string>
#include <iostream>

#include "Socket.h"

Socket::Socket(const char* node, const char* serv, const int flags) :
	skt_fd(-1),
	address(nullptr) {
	struct addrinfo hints {};
	struct addrinfo* result;

	hints.ai_family = AF_INET;			// IPv4
	hints.ai_socktype = SOCK_STREAM;	// TCP
	hints.ai_flags = flags;				// Server: AI_PASSIVE | ClientReceiver: 0

	int s = getaddrinfo(node, serv, &hints, &result);
	if (s != 0) {
		throw CustomException(SOCKET_ERROR, gai_strerror(s));
	}

	this->address = result;

	struct addrinfo *ptr;
	for (ptr = result; ptr != nullptr; ptr = ptr->ai_next) {
		int domain = ptr->ai_family;
		int type = ptr->ai_socktype;
		int protocol = ptr->ai_protocol;
		this->skt_fd = socket(domain, type, protocol);
	}

	if (this->skt_fd == -1) {
		throw CustomException(SOCKET_ERROR, "Socket error");
	}
}

Socket::Socket(const int fd) :
	skt_fd(fd),
	address(nullptr) {}

Socket::~Socket() {
	if (this->address != nullptr) {
		freeaddrinfo(this->address);
	}
	if (this->skt_fd != -1) {
		this->shutdown(SHUT_RDWR);
		::close(this->skt_fd);
	}
}

void Socket::bind() {
	int o = 1;	// one
	if (setsockopt(this->skt_fd, SOL_SOCKET, SO_REUSEADDR, &o, sizeof(o)) == -1) {
		throw CustomException(SOCKET_ERROR, "reusing address error");
	}

	struct sockaddr* address = this->address->ai_addr;
	socklen_t address_len = this->address->ai_addrlen;

	if (::bind(this->skt_fd, address, address_len) == -1) {
		std::string msg = "Binding error: " + std::string(strerror(errno));
		throw CustomException(SOCKET_ERROR, msg.data());
	}
}

void Socket::listen(const int max_request) {
	if (::listen(this->skt_fd, max_request) == -1) {
		std::string msg = "Listening error: " + std::string(strerror(errno));
		throw CustomException(SOCKET_ERROR, msg.data());
	}
}

int Socket::accept() const {
	int peer_socket = ::accept(this->skt_fd, nullptr, nullptr);
	if (peer_socket == -1) {	// manejar error
		std::string msg = "Accepting error: " + std::string(strerror(errno));
		throw CustomException(SOCKET_ERROR, msg.data());
	}
	return peer_socket;
}

void Socket::connect() {
	struct sockaddr* address = this->address->ai_addr;
	socklen_t address_len = this->address->ai_addrlen;

	if (::connect(this->skt_fd, address, address_len) == -1) {
		std::string msg = "Connection error: " + std::string(strerror(errno));
		throw CustomException(SOCKET_ERROR, msg.data());
	}
}

void Socket::sendLength(uint32_t number) const {
	number = ::htonl(number);
	this->send((char*) &number, NUM_SIZE);
}

void Socket::send(const char* buf, size_t size) const {
	size_t sent = 0;
	int len_sent = 0;
	bool open_socket = true;

	while ((sent < size) && open_socket) {
		size_t remaining = size - sent;
		len_sent = ::send(this->skt_fd, &buf[sent], remaining, MSG_NOSIGNAL);

		if (len_sent < 0) {	// Error al enviar
			std::string msg = "Sending error: " + std::string(strerror(errno));
			throw CustomException(SOCKET_ERROR, msg.data());
		} else if  (len_sent == 0) {
			open_socket = false;
		} else {
			sent += len_sent;
		}
	}
}

size_t Socket::receiveLength(uint32_t* number) const {
	size_t b_recv = this->receive((char*) number, NUM_SIZE);
	*number = ::ntohl(*number);
	return b_recv;
}

size_t Socket::receive(char* buf, const uint32_t size) const {
	size_t b_recv = 0;	//	Bytes Recibidos
	int len_recv = 0;
	bool open_socket = true;

	while ((b_recv < size) && (open_socket)) {
		size_t remaining = size - b_recv;
		len_recv = ::recv(this->skt_fd, &buf[b_recv], remaining, MSG_NOSIGNAL);

		if (len_recv < 0) {	// Error al recibir
			std::string msg = "Receiving error: " + std::string(strerror(errno));
			throw CustomException(SOCKET_ERROR, msg.data());
		} else if (len_recv == 0) {	// Socket cerrado
			open_socket = false;
		} else {
			b_recv += len_recv;
		}
	}
	return b_recv;
}

void Socket::close() {
	::close(this->skt_fd);
}

void Socket::shutdown(const int how) {
	::shutdown(this->skt_fd, how);
}
