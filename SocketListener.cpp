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
SocketListener::~SocketListener() {}

int SocketListener::listen() {

	std::cout << "running....\n";
	try {
		// Create the socket
		ServerSocket server(30000);

		while (true) {
			ServerSocket new_sock;

			server.accept(new_sock);

			try {
				while (true) {
					std::string data;
					new_sock >> data;
					new_sock << data;
				}
			} catch (SocketException& se) {
			}
		}
	} catch (std::exception& e) {
		std::cout << "Exception was caught:" << e.what()
				<< "\nExiting.\n";
	}
	return 0;
}
