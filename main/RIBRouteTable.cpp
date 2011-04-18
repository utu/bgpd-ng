#include "RIBRouteTable.hpp"
#include "RoutingTableException.hpp"
#include "RoutingTableEmptyExecption.hpp"

RIBRouteTable::RIBRouteTable() {
	routeTable = static_cast<std::list<RoutePrefix> > (routeTable);
}
RIBRouteTable::~RIBRouteTable() {
}

std::list<RoutePrefix> RIBRouteTable::findBestMatches(const RoutePrefix &route) {
	// TODO: stubb
	return routeTable;
}

Prefix RIBRouteTable::calcNextHop(const Prefix &route) {
	// TODO:: stubb
	return *routeTable.begin();
}

