#ifndef __CLIENTRECEIVER_H__
#define __CLIENTRECEIVER_H__

#include <CommunicationQueue.h>
#include "Thread.h"
#include "Socket.h"
#include <string>

class ClientReceiver : public Thread {
public:
	ClientReceiver(Socket &connectionSkt, CommunicationQueue &queue);

	~ClientReceiver();

	void sendPayload(const std::string& payload);

	virtual void run() override;

	void recvPayload();

	void disconnect();

private:
	bool keepPlaying;
	Socket& connectionSkt;
	CommunicationQueue& queue;
};

#endif	// __CLIENTRECEIVER_H__
