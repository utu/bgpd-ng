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
int RoutePrefix::countMatchingBits(const RoutePrefix &route) {
	return 0;
}

bool RoutePrefix::operator==(const RoutePrefix &comp) {
	return true;
}
