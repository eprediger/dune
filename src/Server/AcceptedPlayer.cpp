#include "AcceptedPlayer.h"
#include <string>
#include <vector>
#include <iostream>
#include <sys/socket.h>

AcceptedPlayer::AcceptedPlayer(Server& server) :
    queue(),
    server(server),
    peerSkt(server.accept()),
    buffer(),
    sender(peerSkt, queue),
    receiver(peerSkt, server.commonQueue),
    id(-1) {}

AcceptedPlayer::~AcceptedPlayer() {
    this->disconnect();
}

void AcceptedPlayer::start() {
    this->receiver.start();
    this->sender.start();
}

void AcceptedPlayer::disconnect() {
    std::cout << "Player disconected" << std::endl;
    sender.disconnect();
    receiver.disconnect();
    this->peerSkt.shutdown(SHUT_RDWR);
    this->peerSkt.close();
    queue.clear();
    sender.join();
    receiver.join();
}

void AcceptedPlayer::setId(int id) {
    this->id = id;
}

int AcceptedPlayer::getId() {
    return this->id;
}

bool AcceptedPlayer::is_alive() {
    return receiver.is_alive() || sender.is_alive();
}
