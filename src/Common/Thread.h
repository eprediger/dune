#ifndef __THREAD_H__
#define __THREAD_H__

#include <thread>

class Thread {
public:
	Thread(); 

	virtual ~Thread();

	Thread(const Thread&) = delete;

	Thread& operator=(const Thread&) = delete;

	void start();

	virtual void run() = 0;

	void join();

	Thread(Thread&& other);

	Thread& operator=(Thread&& other);

private:
	std::thread thread;
};

#endif
