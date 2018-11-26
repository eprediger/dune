#ifndef __CLIENTSENDER_H__
#define __CLIENTSENDER_H__


#include <string>
#include <Socket.h>
#include <Thread.h>
#include <CommunicationQueue.h>

class ClientSender : public Thread {
public:
    ClientSender(Socket &connectionSkt, CommunicationQueue &queue);
    ~ClientSender();

    void sendPayload(const std::string& payload);

    virtual void run() override;

    void recvPayload();

    void disconnect();

private:
    bool keepPlaying;
    Socket& connectionSkt;
    CommunicationQueue& queue;
};


#endif //__CLIENTSENDER_H__
