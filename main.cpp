#include "SocketExample.hpp"

int main(int argc, char* argv[]) {
	SocketExample sl(30000);
	sl.start(); // kick the thread spinning
	sl.join();  // wait for thread to finish

}
