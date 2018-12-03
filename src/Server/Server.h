#ifndef __SERVER_H__
#define __SERVER_H__

#include "Socket.h"
#include "Thread.h"
#include "AcceptedPlayer.h"
#include <vector>
#include "Model/Model.h"
#include "MapReader.h"
#include "ConfigurationReader.h"
#include <Codes.h>

#define MAX_LISTEN 10

class AcceptedPlayer;

class Server {
public:
	explicit Server(const char *service, const char* mapFile);

	~Server();

	void shutdown();

	Socket accept() const;

	void waitPlayers();

	void cleanDisconectedPlayers();

	void disconectAllPlayers();

	CommunicationQueue commonQueue;

private:
	MapReader mapLayout;
	unsigned maxPlayers;
	bool manualShutDown;
	Socket acceptSkt;
	std::vector<AcceptedPlayer*> players;
	Model model;
};

#endif	// __SERVER_H__
