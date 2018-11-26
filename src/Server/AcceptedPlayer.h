#ifndef __ACCEPTED_PLAYER_H__
#define __ACCEPTED_PLAYER_H__

#include "Thread.h"
#include "Socket.h"
#include "Server.h"
#include <string>

class Server;

class AcceptedPlayer : public Thread {
public:
	AcceptedPlayer(Server& server);

	~AcceptedPlayer();

	void sendResponse(const std::string& msg);
private:

	void run() override;

private:
	Server& server;
	const Socket peerSkt;
	std::string buffer;
};

#endif	// __ACCEPTED_PLAYER_H__
