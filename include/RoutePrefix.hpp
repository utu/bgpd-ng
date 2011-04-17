#ifndef ROUTEPREFIX_HPP_
#define ROUTEPREFIX_HPP_

#include "RoutePrefix.hpp";

class RoutePrefix {
public:
	bool matches(RoutePrefix &rtable);
	int getASPathLength();
	bool isStatic();
	int countMatchingBits(const RoutePrefix &route);
	bool operator==(const RoutePrefix &comp);
};

#endif
