#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "../common/Thread.h"
#include "../common/Socket.h"

class Client : public Thread {
public:
	Client(const char* host, const char* service);
	~Client();

	void sendPayload(const std::string& payload);

	virtual void run() override;

	void recvPayload();

	void disconnect();

private:
	bool keepPlaying;
	Socket connectionSkt;
};

#endif	// __CLIENT_H__
