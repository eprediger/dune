#define _POSIX_C_SOURCE 200112L
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <ClientReceiver.h>

#include <memory>
#include <iostream>
#include <string>

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
		this->connectionSkt.receiveLength(&length);
		std::unique_ptr<char[]> buffer(new char[length + 1]());
		this->connectionSkt.receive(&buffer[0], length);
		nlohmann::json recv = nlohmann::json::parse(buffer.get());
		queue.putReceived(recv);
	}
}

void ClientReceiver::disconnect() {
	this->keepPlaying = false;
}
