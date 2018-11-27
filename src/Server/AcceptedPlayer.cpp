#include "AcceptedPlayer.h"
#include <string>
#include <vector>
#include <iostream>
#include <sys/socket.h>

// #include <nlohmann/json.hpp>

AcceptedPlayer::AcceptedPlayer(Server& server) :
    server(server),
	peerSkt(server.accept()),
	buffer(),
	queue(),
	sender(peerSkt,queue),
	receiver(peerSkt,server.commonQueue) {}

AcceptedPlayer::~AcceptedPlayer() {}

void AcceptedPlayer::start(){
	this->receiver.start();
	this->sender.start();
}

void AcceptedPlayer::disconnect(){
    sender.disconnect();
    receiver.disconnect();
    this->peerSkt.shutdown(SHUT_RDWR);
    this->peerSkt.close();
    sender.join();
    receiver.join();
}


