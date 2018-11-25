#ifndef __SERVER_EXIT_THREAD_H__
#define __SERVER_EXIT_THREAD_H__

#include "Server.h"
#include "../common/Thread.h"

class Server;

class ExitThread : public Thread {
public:
	explicit ExitThread(Server& server);

	~ExitThread();

protected:
	void run() override;

private:
	Server& server;
};

#endif	// __SERVER_EXIT_THREAD_H__
