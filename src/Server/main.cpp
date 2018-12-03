#include <cstdlib>
#include <iostream>
#include "Server.h"
#include "ExitThread.h"

int main(int argc, char const *argv[]) {
	if (argc != SRV_ARGS) {
		std::cerr << "Uso: " << argv[0]
		          << " <puerto> <mapa.yaml>" << std::endl;
		return PARAM_ERROR;
	} else {
		Server gameServer(argv[1], argv[2]);
		ExitThread exitThread(gameServer);
//		try {
			exitThread.start();
			gameServer.waitPlayers();
			exitThread.join();
			return SUCCESS;
//		} catch (const CustomException& ce) {
//			std::cerr << ce.what() << std::endl;
//			exitThread.join();
//			return ce.getErrorCode();
//		} catch (std::exception& e) {
//			std::cerr << e.what() << std::endl;
//			exitThread.join();
//			return EXIT_FAILURE;
//		}
	}
}
