#ifndef __COMMUNICATIONQUEUE_H__
#define __COMMUNICATIONQUEUE_H__


#include <string>
#include <queue>
#include <json.hpp>

class CommunicationQueue {
public:
    void enqueue(nlohmann::json send_json);

    nlohmann::json dequeue();

    void putReceived(nlohmann::json send_json);
    nlohmann::json getSend();

    bool sendEmpty();
    bool recvEmpty();

private:
    std::queue<nlohmann::json> send_queue;
    std::queue<nlohmann::json> recv_queue;
};


#endif //DUNE_COMMUNICATIONQUEUE_H
