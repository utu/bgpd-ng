#include "SocketListener.hpp"

int main(int argc, char* argv[]) {
	SocketListener sl(30000);
	sl.start();
	sl.join();

}
