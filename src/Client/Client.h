#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <Socket.h>
#include <CommunicationQueue.h>
#include <ClientReceiver.h>
#include <ClientSender.h>

class Client {
public:
	Client(const char *host, const char *service, CommunicationQueue &queue);
	~Client();

	void start();

	void disconnect();
private:
	bool keepPlaying;
	Socket connectionSkt;
	CommunicationQueue& queue;
	ClientReceiver receiver;
	ClientSender sender;
};

#endif //__CLIENT_H__
