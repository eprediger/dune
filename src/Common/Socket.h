#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "Codes.h"
#include "CustomException.h"
#include <string>
#include <vector>

#define NUM_SIZE 4

class Socket {
public:
	Socket(const char* node, const char* serv, const int flags);

	explicit Socket(const int fd);

	~Socket();

	void bind();

	void listen(const int max_request);

	int accept() const;

	void connect();

	void sendLength(uint32_t number) const;

	void send(const char* buf, size_t size) const;

	size_t receiveLength(uint32_t* number) const;

	size_t receive(char* buf, uint32_t size) const;

	void close();

	void shutdown(const int how);

private:
	int skt_fd;
	struct addrinfo* address;
};

#endif	// __SOCKET_H__
