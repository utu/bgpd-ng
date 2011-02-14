#ifndef SOCKETLISTENER_HPP_
#define SOCKETLISTENER_HPP_

#include <boost/thread.hpp>

class SocketListener {
public:
	SocketListener(int port);
	SocketListener(const SocketListener& source);
	virtual ~SocketListener();

	// equal to run()
	void start();
	void join();

private:
	int sock_port;
	boost::thread m_Thread;

	void run();
};


#endif /* SOCKETLISTENER_HPP_ */
