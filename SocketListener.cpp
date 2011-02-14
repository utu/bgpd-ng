#include <boost/thread.hpp>
#include <exception>
#include <iostream>
#include <string>
#include "SocketListener.hpp"
#include "SocketException.hpp"
#include "Socket.hpp"
#include "ServerSocket.hpp"

SocketListener::SocketListener(int port) : sock_port(port) {
}
SocketListener::SocketListener(const SocketListener& source): sock_port(source.sock_port) {
}
SocketListener::~SocketListener() {}

void SocketListener::start() {
	m_Thread = boost::thread(&SocketListener::run, this);
}
void SocketListener::join() {
	m_Thread.join();
}

void SocketListener::run() {

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

