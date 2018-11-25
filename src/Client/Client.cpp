#define _POSIX_C_SOURCE 200112L
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "Client.h"

#include <memory>
#include <iostream>

Client::Client(const char* host, const char* service) :
	keepPlaying(true),
	connectionSkt(host, service, 0) {
	this->connectionSkt.connect();
}

Client::~Client() {
	if (keepPlaying) {
		this->disconnect();
	}
}

void Client::sendPayload(const std::string& payload) {
	this->connectionSkt.sendLength(payload.length());
	this->connectionSkt.send(payload.c_str(), payload.length());
}

void Client::run() {
	this->recvPayload();
}

void Client::recvPayload() {
	uint32_t length = 0;
	this->connectionSkt.receiveLength(&length);
	std::unique_ptr<char[]> buffer(new char[length + 1]());
	this->connectionSkt.receive(&buffer[0], length);
	std::cout << buffer.get();
}

void Client::disconnect() {
	this->keepPlaying = false;
	this->connectionSkt.shutdown(SHUT_RDWR);
	this->connectionSkt.close();
}