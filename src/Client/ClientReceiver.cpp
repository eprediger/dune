#define _POSIX_C_SOURCE 200112L
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "ClientReceiver.h"

#include <memory>
#include <iostream>

ClientReceiver::ClientReceiver(Socket &connectionSkt, CommunicationQueue &queue) :
	keepPlaying(true),
	connectionSkt(connectionSkt),
	queue(queue) {}

ClientReceiver::~ClientReceiver() {
	if (keepPlaying) {
		this->disconnect();
	}
}

void ClientReceiver::sendPayload(const std::string& payload) {
	this->connectionSkt.sendLength(payload.length());
	this->connectionSkt.send(payload.c_str(), payload.length());
}

void ClientReceiver::run() {
	this->recvPayload();
}

void ClientReceiver::recvPayload() {
	uint32_t length = 0;
	while (this->keepPlaying) {
//		std::cout << "[Se recibira largo]" << std::endl;
		this->connectionSkt.receiveLength(&length);
//		std::cout << "[Se recibira mensaje]" << std::endl;
		std::unique_ptr<char[]> buffer(new char[length + 1]());
		this->connectionSkt.receive(&buffer[0], length);
//		std::cout << "[Se recibio el mensaje. Se imprimira]" << std::endl;
//		std::cerr << buffer.get(); // << std::endl;
		nlohmann::json recv = nlohmann::json::parse(buffer.get());
		queue.putReceived(recv);
//		std::cout << "[Se imprimio el mensaje]" << std::endl;
	}
}

void ClientReceiver::disconnect() {
	this->keepPlaying = false;
}