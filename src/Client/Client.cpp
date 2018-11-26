#include <sys/socket.h>
#include "Client.h"

Client::Client(const char *host, const char *service, CommunicationQueue &queue) :
    keepPlaying(true),
    connectionSkt(host, service, 0),
    queue(queue),
    receiver(connectionSkt, queue),
    sender(connectionSkt, queue) {
    this->connectionSkt.connect();
}

Client::~Client() {
    if (keepPlaying) {
        this->disconnect();
    }
}

void Client::disconnect() {
    this->keepPlaying = false;
    sender.disconnect();
    receiver.disconnect();
    this->connectionSkt.shutdown(SHUT_RDWR);
    this->connectionSkt.close();
    sender.join();
    receiver.join();
}

void Client::run() {
    receiver.start();
    sender.start();
}


