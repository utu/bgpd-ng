#include <boost/thread.hpp>
#include <exception>
#include <iostream>
#include <string>
#include "SocketListener.hpp"

SocketListener::SocketListener(int port) : sock_port(port) {

}

int SocketListener::listen() {

	std::cout << "running....\n";
	try {
		// Create the socket
		ServerSocket server(sck_port);

		while (true) {

			Socket new_sock;
			server.accept(new_sock);

			try {
				while (true) {
					std::string data;
					new_sock >> data;
					new_sock << data;
				}
			} catch (SocketException&) {
			}

		}
	} catch (Exception& e) {
		std::cout << "Exception was caught:" << e.description()
				<< "\nExiting.\n";
	}

	return 0;
}

