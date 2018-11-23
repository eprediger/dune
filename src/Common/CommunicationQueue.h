#ifndef __COMMUNICATIONQUEUE_H__
#define __COMMUNICATIONQUEUE_H__


#include <string>
#include <queue>
#include <json.hpp>

class CommunicationQueue {
public:
    void enqueue(nlohmann::json send_json);

    nlohmann::json dequeue();

    bool isEmpty();

private:
    std::queue<nlohmann::json> send_queue;
};


#endif //DUNE_COMMUNICATIONQUEUE_H
