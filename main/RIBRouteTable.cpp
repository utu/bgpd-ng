#include "RIBRouteTable.hpp"
#include "RoutingTableException.hpp"
#include "RoutingTableEmptyExecption.hpp"

RIBRouteTable::RIBRouteTable() {
}
RIBRouteTable::~RIBRouteTable() {
}

std::list<RoutePrefix> RIBRouteTable::findBestMatches(const RoutePrefix &route) {

	std::list<RoutePrefix> *helpTable = new std::list<RoutePrefix>();
	std::list<RoutePrefix>::iterator routeIt;

//	for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
//
//		if (route.countMatchingBits(routeIt) == findLongestMatchLength(route)) {
//			helpTable->push_back(*routeIt);
//		}
//	}
//	return helpTable;

}

RoutePrefix RIBRouteTable::calcNextHop(const Prefix &route) {

}

