#include "RoutePrefix.hpp"

// TODO: Stubb

bool RoutePrefix::matches(RoutePrefix &rtable) {
	return true;
}
int RoutePrefix::getASPathLength() {
	return 0;
}

bool RoutePrefix::isStatic() {
	return true;
}
static int RoutePrefix::countMatchingBits(RoutePrefix &route1, RoutePrefix &route2) {
	return 0;
}