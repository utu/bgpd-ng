#ifndef ROUTEPREFIX_HPP_
#define ROUTEPREFIX_HPP_

#include "RoutePrefix.hpp";

class RoutePrefix {
public:
	bool matches(RoutePrefix &rtable);
	int getASPathLength();
	bool isStatic();
	static int countMatchingBits(RoutePrefix &route1, RoutePrefix &route2);
};
#endif
