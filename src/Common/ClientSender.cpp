#include "../Common/ClientSender.h"

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <memory>
#include <iostream>
#include <string>
#include <CommunicationQueue.h>

ClientSender::ClientSender(Socket &connectionSkt, CommunicationQueue &queue) :
    keepPlaying(true),
    connectionSkt(connectionSkt),
    queue(queue) {}

ClientSender::~ClientSender() {
    if (keepPlaying) {
        this->disconnect();
    }
}

void ClientSender::sendPayload(const std::string& payload) {
    this->connectionSkt.sendLength(payload.length());
    this->connectionSkt.send(payload.c_str(), payload.length());
}

void ClientSender::run() {
    while (this->keepPlaying) {
        nlohmann::json send = queue.getSend();
        this->sendPayload(send.dump());
    }
}

void ClientSender::disconnect() {
    this->keepPlaying = false;
}
