#include "AcceptedPlayer.h"
#include <string>
#include <vector>
#include <iostream>
// #include <nlohmann/json.hpp>

AcceptedPlayer::AcceptedPlayer(Server& server) :
    server(server),
	peerSkt(server.accept()),
	buffer() {}

AcceptedPlayer::~AcceptedPlayer() {}

void AcceptedPlayer::run() {
	bool running = true;
	while (running) {
		uint32_t length = 0;
		size_t received = this->peerSkt.receiveLength(&length);
		std::unique_ptr<char[]> buffer(new char[length]());
		this->peerSkt.receive(&buffer[0], length);
		this->buffer = std::string(&buffer[0], length);
		std::cout << "[Mensaje Recibido: " << this->buffer << "]" << std::endl;
		running = (received > 0);
		if (running) {
			this->server.notifyAll(this->buffer);
		}
		this->buffer.clear();
	}
}

void AcceptedPlayer::sendResponse(const std::string& msg) {
	this->peerSkt.sendLength(msg.length() + 1);
	this->peerSkt.send(msg.c_str(), msg.length() + 1);
}
