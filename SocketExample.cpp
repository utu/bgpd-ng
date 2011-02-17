#include <boost/thread.hpp>
#include <boost/regex.hpp>
#include <exception>
#include <iostream>
#include <string>
#include "SocketExample.hpp"
#include "SocketException.hpp"
#include "Socket.hpp"
#include "ServerSocket.hpp"

SocketExample::SocketExample(int port) : sock_port(port) {
}
SocketExample::SocketExample(const SocketExample& source): sock_port(source.sock_port) {
}
SocketExample::~SocketExample() {}

void SocketExample::start() {
	m_Thread = boost::thread(&SocketExample::run, this);
}
void SocketExample::join() {
	m_Thread.join();
}

void SocketExample::run() {
	boost::regex  expression("^omg_lol die.*");

	std::cout << "running....\n";
	try {
		// Create the socket
		ServerSocket server(sock_port);

		while (true) {
			ServerSocket new_sock;

			server.accept(new_sock);

			try {
				while (true) {
					std::string data;
					new_sock >> data;

					boost::cmatch match;
					if (regex_match(data.c_str(), match, expression)) {
						throw(SocketException(std::string(match[0])));
					}
					std::cout << data;
				}
			} catch (SocketException& se) {
			}
		}
	} catch (std::exception& e) {
		std::cout << "Exception was caught:" << e.what()
				<< "\nExiting.\n";
	}
}

