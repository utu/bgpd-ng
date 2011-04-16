#ifndef BGPROUTEPREFIX_HPP_
#define BGPROUTEPREFIX_HPP_

#include <string>
#include <list>
#include "RoutePrefix.hpp"

class BGPRoutePrefix : RoutePrefix {

private:
	BGPRoutePrefix* nextHop;
	std::list<std::string> asPath;
};
#endif
