#ifndef __SERVER_H__
#define __SERVER_H__

#include "../common/Socket.h"
#include "../common/Thread.h"
#include "AcceptedPlayer.h"
#include <vector>

#define MAX_LISTEN 10

class AcceptedPlayer;

class Server {
public:
	explicit Server(const char *service, unsigned int players);
	
	~Server();

	void shutdown();

	Socket accept() const;

	void waitPlayers();

	void notifyAll(const std::string& msg);

private:
	unsigned maxPlayers;
	bool manualShutDown;
	Socket acceptSkt;
	std::vector<AcceptedPlayer*> players;
};

#endif	// __SERVER_H__
