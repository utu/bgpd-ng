#ifndef SocketExample_HPP_
#define SocketExample_HPP_

#include <boost/thread.hpp>

class SocketExample {
public:
	SocketExample(int port);
	SocketExample(const SocketExample& source);
	virtual ~SocketExample();

	// equal to run()
	void start();
	void join();

private:
	int sock_port;
	boost::thread m_Thread;

	void run();
};


#endif /* SocketExample_HPP_ */
