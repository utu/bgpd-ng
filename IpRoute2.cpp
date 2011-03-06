#include "IpRoute2.hpp"
#include <unistd.h>

void IpRoute2::addRoute(const char * interface, const char * route) {
	std::string cmd;
	cmd << "ip route add " << route << " dev " << interface;
	int ret = system(cmd);
}

void IpRoute2::flushRoutes() {
	int ret = system("ip route flush");
}
