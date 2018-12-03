#ifndef __HANDLERTHREAD_H__
#define __HANDLERTHREAD_H__

#include <Thread.h>
#include "Application.h"

class HandlerThread : public Thread {
public:
	explicit HandlerThread(Application& app);

	virtual ~HandlerThread() = default;

	virtual void run() override;

    void stop();

private:
	Application& app;
};

#endif	// __HANDLERTHREAD_H__
