#include <cstdarg>
#include "CommunicationQueue.h"

void CommunicationQueue::enqueue(nlohmann::json send_json) {
    send_queue.push(send_json);
//    recv_queue.push(send_json);
}

nlohmann::json CommunicationQueue::dequeue() {
    nlohmann::json ret_json;
    if (!recv_queue.empty()){
        ret_json = recv_queue.front();
        recv_queue.pop();
        return ret_json;
    }
    return ret_json;
}

bool CommunicationQueue::sendEmpty() {
    return send_queue.empty();
}

void CommunicationQueue::putReceived(nlohmann::json send_json) {
    recv_queue.push(send_json);
}

bool CommunicationQueue::recvEmpty() {
    return recv_queue.empty();
}

nlohmann::json CommunicationQueue::getSend() {
    nlohmann::json ret_json;
    if (!send_queue.empty()){
        ret_json = send_queue.front();
        send_queue.pop();
        return ret_json;
    }
    return ret_json;
}
