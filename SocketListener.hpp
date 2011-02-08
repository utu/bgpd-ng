#ifndef SOCKETLISTENER_HPP_
#define SOCKETLISTENER_HPP_

class SocketListener {
public:
	SocketListener(int port);
	virtual ~SocketListener();

	int listen();

private:
	int sock_port;
};


#endif /* SOCKETLISTENER_HPP_ */
