#define _POSIX_C_SOURCE 200112L
#include <sys/socket.h>
#include <chrono>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <yaml-cpp/yaml.h>
#include "Server.h"
#include "Model/Model.h"
#include "CustomException.h"
#include <algorithm>
#include <SDL2/SDL.h>
#include "GameInterface.h"

Server::Server(const char *service, const char* mapFile) :
	commonQueue(),
	config(mapFile),
	maxPlayers(config.getPlayers()),
	manualShutDown(false),
	acceptSkt(nullptr, service, AI_PASSIVE),
	players(),
	model(mapFile) {
	this->acceptSkt.bind();
	this->acceptSkt.listen(MAX_LISTEN);
}

Server::~Server() {
	if (!manualShutDown) {
		this->shutdown();
	}
	std::for_each(this->players.begin(), this->players.end(),
	[](AcceptedPlayer *&AcceptedPlayer) {
		AcceptedPlayer->disconnect();
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
#include <SDL_timer.h>

void Server::waitPlayers() {
	GameInterface interface(model);
	std::cout << "Start to acept Players" << std::endl;
	for (unsigned i = 0; i < this->maxPlayers; ++i) {
		this->players.push_back(new AcceptedPlayer(*this));
		std::cout << "Player Acepted!" << std::endl;
	}
	std::cout << "Start Program!!!" << std::endl;
	for (unsigned i = 0; i < this->maxPlayers; ++i) {
		this->players[i]->start();
		model.addPlayer();
		this->players[i]->queue.enqueue(model.getMap().getSerialization());
		this->players[i]->queue.enqueue(model.getPlayer(i).getSerialization());
		this->players[i]->setId(i);
	}

	for (unsigned i = 0; i < this->maxPlayers; ++i) {
		for (unsigned j = 0; j < this->maxPlayers; ++j) {
			this->players[i]->queue.enqueue(model.getPlayer(j).getSerialization());
		}
	}

	nlohmann::json j;
	j["class"] = "Step";
	const int time_step = 16;
	int sleep_extra = 0;
	while (!model.isGameFinished()) {
		unsigned int loop_init = SDL_GetTicks();
		model.step();
		model.serialize(players);
		if (!commonQueue.recvEmpty())
			interface.execute(commonQueue.dequeue());

		for (auto player: players){
			player->queue.enqueue(j);
		}
		
		unsigned int loop_end = SDL_GetTicks();

		int step_duration = (loop_end - loop_init);
		int sleep_delay = time_step - step_duration - sleep_extra;
		sleep_delay = (sleep_delay < 0) ? 0 : sleep_delay;

		SDL_Delay(sleep_delay);
		unsigned int delay_end = SDL_GetTicks();

		sleep_extra = (delay_end - loop_end) - sleep_delay;
	}
}
