#define _POSIX_C_SOURCE 200112L
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "Server.h"
#include "CustomException.h"
#include <algorithm>

Server::Server(const char *service, unsigned int players) :
	maxPlayers(players),
	manualShutDown(false),
	acceptSkt(nullptr, service, AI_PASSIVE),
	players() {
	this->acceptSkt.bind();
	this->acceptSkt.listen(MAX_LISTEN);
}

Server::~Server() {
	if (!manualShutDown) {
		this->shutdown();
	}
	std::for_each(this->players.begin(), this->players.end(),
	[](AcceptedPlayer *&AcceptedPlayer) {
		AcceptedPlayer->join();
		delete AcceptedPlayer;
	});
}

void Server::shutdown() {
	this->manualShutDown = true;
	this->acceptSkt.shutdown(SHUT_RDWR);
	this->acceptSkt.close();
}

Socket Server::accept() const {
	try {
		int peerSkt = this->acceptSkt.accept();
		if (peerSkt == -1) {
			throw CustomException("Server error");
		}
		return Socket(peerSkt);
	} catch (const std::runtime_error &error) {
		throw CustomException("Server error");
	}
}

#include <iostream>
void Server::waitPlayers() {
	std::cout << "Start to acept Players" << std::endl;
	for (unsigned i = 0; i < this->maxPlayers; ++i) {
		this->players.push_back(new AcceptedPlayer(*this));
		std::cout << "Player Acepted!" << std::endl;
	}
	std::cout << "Start Program!!!" << std::endl;
	for (unsigned i = 0; i < this->maxPlayers; ++i) {
		this->players[i]->start();
	}
}

void Server::notifyAll(const std::string& msg) {
	for (unsigned i = 0; i < this->maxPlayers; ++i) {
		this->players[i]->sendResponse(msg);
	}
}
