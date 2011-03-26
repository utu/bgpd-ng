#ifndef BGPROUTEPREFIX_HPP_
#define BGPROUTEPREFIX_HPP_

#include <string>
#include "RoutePrefix.hpp"

class BGPRoutePrefix : RoutePrefix {

private:
	BGPRoutePrefix* nextHop;
	List<std::string> asPath;
};
#endif
