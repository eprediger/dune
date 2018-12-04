#include <ClientSender.h>

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <memory>
#include <string>
#include <CommunicationQueue.h>
#include "ClientSender.h"

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
    if (this->keepPlaying) {
        this->connectionSkt.send(payload.c_str(), payload.length());
    }
}

void ClientSender::run() {
    try {
        while (this->keepPlaying) {
            nlohmann::json send = queue.getSend();
            this->sendPayload(send.dump());
        }
    } catch (CustomException& e) {
        this->keepPlaying = false;
    }
}

void ClientSender::disconnect() {
    this->keepPlaying = false;
}

bool ClientSender::is_alive() {
    return this->keepPlaying;
}
