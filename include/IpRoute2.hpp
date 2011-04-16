#ifndef IPROUTE2_HPP_
#define IPROUTE2_HPP_

class IpRoute2 {
public:

	void addRoute(const char * interface, const char * route);
	//void delRoute(const char * interface, const char * route);
	void flushRoutes();

};

#endif
