#include <cstdarg>
#include "CommunicationQueue.h"

void CommunicationQueue::enqueue(nlohmann::json send_json) {
    send_queue.push(send_json);
}

nlohmann::json CommunicationQueue::dequeue() {
    nlohmann::json ret_json;
    if (!send_queue.empty()){
        ret_json = send_queue.front();
        send_queue.pop();
        return ret_json;
    }
    return ret_json;
}
