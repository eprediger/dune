#ifndef __ACCEPTED_PLAYER_H__
#define __ACCEPTED_PLAYER_H__

#include "Thread.h"
#include "Socket.h"
#include "Server.h"
#include <string>
#include "../Common/ClientSender.h"
#include "../Common/ClientReceiver.h"

class Server;

class AcceptedPlayer {
public:
	explicit AcceptedPlayer(Server& server);

	~AcceptedPlayer();

	void start();

	void disconnect();

	void setId(int id);

	int getId();

	CommunicationQueue queue;

private:
	Server& server;
	Socket peerSkt;
	std::string buffer;
	ClientSender sender;
	ClientReceiver receiver;
	int id;
};

#endif	// __ACCEPTED_PLAYER_H__
