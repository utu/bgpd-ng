#ifndef SERVERSOCKET_HPP_
#define SERVERSOCKET_HPP_

#include "Socket.hpp"

class ServerSocket: private Socket {
public:

	ServerSocket(int port);
	ServerSocket() {};
	virtual ~ServerSocket();

	const ServerSocket& operator <<(const std::string&) const;
	const ServerSocket& operator >>(std::string&) const;

	void accept(ServerSocket&);

};

#endif /* SERVERSOCKET_HPP_ */
