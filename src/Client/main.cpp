#include <iostream>
#include <string>

#include <nlohmann/json.hpp>
#include "Client.h"
#include "../common/Codes.h"

// ./client 127.0.0.1 10001 ORDOS

int main(int argc, char const *argv[]) {
	if (argc != CLT_ARGS) {
		std::cerr << "Uso: " << argv[0]
		          << " <ip-servidor> <puerto-servidor> <casa>" << std::endl;
		return USAGE_ERROR;
	} else {
		try {
			Client cliente(argv[1], argv[2]);
			std::string input;
			cliente.start();
			while (getline(std::cin, input)) {
				cliente.sendPayload(input);
				// cliente.recvPayload();
			}
			cliente.disconnect();
			cliente.join();
		} catch (const CustomException& ce) {
			std::cerr << ce.what() << std::endl;
			cliente.join();
			return ce.getErrorCode();
		}
		return SUCCESS;
	}
}
