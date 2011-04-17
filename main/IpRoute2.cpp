#include "IpRoute2.hpp"
#include <unistd.h>
#include <string>

void IpRoute2::addRoute(const char * interface, const char * route) {
	std::string cmd;
	cmd.append("ip route add ");
	cmd.append(route);
	cmd.append(" dev ");
	cmd.append(interface);
	int ret = system(cmd.c_str());
}

void IpRoute2::flushRoutes() {
	int ret = std::system("ip route flush");
}
