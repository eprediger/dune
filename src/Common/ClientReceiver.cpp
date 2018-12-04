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
#include "ClientReceiver.h"

ClientReceiver::ClientReceiver(Socket &connectionSkt,
                               CommunicationQueue &queue) :
	keepPlaying(true),
	connectionSkt(connectionSkt),
	queue(queue) {}

ClientReceiver::~ClientReceiver() {
	if (keepPlaying) {
		this->disconnect();
	}
}

void ClientReceiver::run() {
	try {
		this->recvPayload();
		this->keepPlaying = false;
	} catch (CustomException& e) {
		this->keepPlaying = false;
	}
}

void ClientReceiver::recvPayload() {
	uint32_t length = 0;
	while (this->keepPlaying && queue.isWorking()) {
		if (this->connectionSkt.receiveLength(&length) == 0) break;
		std::unique_ptr<char[]> buffer(new char[length + 1]());
		if (this->connectionSkt.receive(&buffer[0], length) == 0) break;
		nlohmann::json recv = nlohmann::json::parse(buffer.get());
		queue.putReceived(recv);
	}
}

void ClientReceiver::disconnect() {
	this->keepPlaying = false;
}

bool ClientReceiver::is_alive() {
	return this->keepPlaying;
}
