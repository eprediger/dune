#include <iostream>
#include <string>

#include <nlohmann/json.hpp>
#include "Model/GlobalConfig.h"

#include "Codes.h"
#include "Client.h"

// ./client 127.0.0.1 10001 ORDOS

config_t GlobalConfig;

int main(int argc, char const *argv[]) {
	if (argc != CLT_ARGS) {
		std::cerr << "Uso: " << argv[0]
		          << " <ip-servidor> <puerto-servidor> <casa>" << std::endl;
		return USAGE_ERROR;
	} else {
		CommunicationQueue queue;
		Client client(argv[1], argv[2], queue);
		try {
//			ClientReceiver client(argv[1], argv[2]);
			std::string input;
			client.start();
			while (getline(std::cin, input)) {
			    if (input != ""){
                    nlohmann::json send;
                    send["message"] = input;
                    queue.enqueue(send);
			    } else {
//                std::cout << "mensaje encolado" << send.dump() << std::endl;
                    while (!queue.recvEmpty()) {
//				    std::cout << "mensaje desencolado" << std::endl;
                        nlohmann::json recv = queue.dequeue();
                        std::cout << recv["message"] << std::endl;
                    }
                }
				// client.sendPayload(input);
				// client.recvPayload();
			}
			client.disconnect();
//			client.join();
		} catch (const CustomException& ce) {
			std::cerr << ce.what() << std::endl;
//			client.join();
			return ce.getErrorCode();
		}
		return SUCCESS;
	}
}
