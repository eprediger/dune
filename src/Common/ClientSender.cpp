#include <ClientSender.h>

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <memory>
#include <iostream>
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
        if (this->connectionSkt.sendLength(payload.length()) == 0) {
            std::cout << "sendLength devuelve 0!" << std::endl;
        }
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
        std::cout << "Exception en el sender!" << std::endl;
    }
    std::cout << "Finaliza el sender!" << std::endl;
}

void ClientSender::disconnect() {
    this->keepPlaying = false;
    std::cout << "Disconect el sender!" << std::endl;
}

bool ClientSender::is_alive() {
    return this->keepPlaying;
}
