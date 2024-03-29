#include "CommunicationQueue.h"

void CommunicationQueue::enqueue(nlohmann::json send_json) {
    std::unique_lock<std::mutex> lock{send_m};
    send_queue.push(send_json);
    lock.unlock();
    condNewSendData.notify_one();
}

nlohmann::json CommunicationQueue::dequeue() {
    std::unique_lock<std::mutex> lock{recv_m};
    while (recv_queue.empty() && working) {
        condNewRecvData.wait(lock);
    }
    nlohmann::json ret_json = std::move(recv_queue.front());
    recv_queue.pop();
    return ret_json;
}

bool CommunicationQueue::sendEmpty() {
    return send_queue.empty();
}

void CommunicationQueue::putReceived(nlohmann::json send_json) {
    std::unique_lock<std::mutex> lock{recv_m};
    recv_queue.push(send_json);
    lock.unlock();
    condNewRecvData.notify_one();
}

bool CommunicationQueue::recvEmpty() {
    return recv_queue.empty();
}

nlohmann::json CommunicationQueue::getSend() {
    std::unique_lock<std::mutex> lock{send_m};
    while (send_queue.empty() && working) {
        condNewSendData.wait(lock);
    }
    if (!working) return nullptr;
    nlohmann::json ret_json = std::move(send_queue.front());
    send_queue.pop();
    return ret_json;
}

CommunicationQueue::CommunicationQueue() : working(true) {}

void CommunicationQueue::clear() {
    working = false;
    condNewRecvData.notify_all();
    condNewSendData.notify_all();
}

bool CommunicationQueue::isWorking() {
    return this->working;
}
