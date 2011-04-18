#ifndef BGPROUTEPREFIX_HPP_
#define BGPROUTEPREFIX_HPP_

#include <string>
#include <list>
#include "RoutePrefix.hpp"

class BGPRoutePrefix : public RoutePrefix {
	const __uint16_t getASPathLength();
private:
	BGPRoutePrefix* nextHop;
};
#endif
