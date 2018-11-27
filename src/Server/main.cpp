#include <cstdlib>
#include <iostream>
#include "Model/GlobalConfig.h"
#include "Server.h"
#include "ExitThread.h"

config_t GlobalConfig;

#define BASE 10

// ./server 10001 2 mapa.yaml

int main(int argc, char const *argv[]) {
	if (argc != SRV_ARGS) {
		std::cerr << "Uso: " << argv[0]
		          << " <puerto> <jugadores> <mapa.yaml>" << std::endl;
		return PARAM_ERROR;
	} else {
		try {
			Server gameServer(argv[1], (unsigned) strtoul(argv[2], NULL, BASE),argv[3]);
			ExitThread exitThread(gameServer); 
			exitThread.start();
			gameServer.waitPlayers();
			exitThread.join();
			return SUCCESS;
		} catch (const CustomException& ce) {
			std::cerr << ce.what() << std::endl;
			return ce.getErrorCode();
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			return EXIT_FAILURE;
		} catch (...) {
			std::cerr << "Todo termino señores, no tenemos escapatoria" << std::endl;
			return EXIT_FAILURE;
		}
	}
}
