#include "ExitThread.h"
#include <iostream>
#include <string>

ExitThread::ExitThread(Server& server) :
	server(server) {}

ExitThread::~ExitThread() {}

void ExitThread::run() {
	std::string instruction;
	do {
		std::cin >> instruction;
	} while (instruction != "q");
	this->server.shutdown();
}
