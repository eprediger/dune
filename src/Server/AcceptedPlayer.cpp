#include "AcceptedPlayer.h"
#include <string>
#include <vector>
#include <iostream>
#include <sys/socket.h>

// #include <nlohmann/json.hpp>

AcceptedPlayer::AcceptedPlayer(Server& server) :
    queue(),
    server(server),
    peerSkt(server.accept()),
    buffer(),
    sender(peerSkt, queue),
    receiver(peerSkt, server.commonQueue),
    id(-1) {}

AcceptedPlayer::~AcceptedPlayer() {}

void AcceptedPlayer::start() {
    this->receiver.start();
    this->sender.start();
}

void AcceptedPlayer::disconnect() {
    sender.disconnect();
    receiver.disconnect();
    this->peerSkt.shutdown(SHUT_RDWR);
    this->peerSkt.close();
    sender.join();
    receiver.join();
}

void AcceptedPlayer::setId(int id) {
    this->id = id;
}

int AcceptedPlayer::getId() {
    return this->id;
}
