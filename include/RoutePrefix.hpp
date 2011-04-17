#ifndef ROUTEPREFIX_HPP_
#define ROUTEPREFIX_HPP_

#include <inttypes.h>
#include "Prefix.hpp"

class RoutePrefix: public Prefix {
public:
	const bool matches(RoutePrefix &rtable);
	const bool isStatic();
};

#endif
