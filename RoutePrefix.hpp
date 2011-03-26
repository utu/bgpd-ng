#ifndef ROUTEPREFIX_HPP_
#define ROUTEPREFIX_HPP_

#include "RoutePrefix.hpp";

class RoutePrefix {
public:
	bool matches(RoutePrefix &rtable);
	int getASPathLength();
};
#endif
