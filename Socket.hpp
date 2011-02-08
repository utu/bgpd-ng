#ifndef Socket_HPP_
#define Socket_HPP_

#include <sys/types.h>
#include <sys/Socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket {
public:
	Socket();
	virtual ~Socket();

	// Server initialization
	bool create();
	bool bind(const int port);
	bool listen() const;
	bool accept(Socket&) const;

	// Client initialization
	bool connect(const std::string host, const int port);

	// Data Transmission
	bool send(const std::string) const;
	int recv(std::string&) const;

	void set_non_blocking(const bool);

	bool is_valid() const;

private:
	int m_sock;
	sockaddr_in m_addr;

};

#endif /* Socket_HPP_ */
