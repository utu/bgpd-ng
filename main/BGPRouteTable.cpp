#include "BGPRouteTable.hpp"
#include "RoutingTableException.hpp"
#include "RoutingTableEmptyExecption.hpp"

BGPRouteTable::BGPRouteTable() {
	routeTable = static_cast<std::list<BGPRoutePrefix> > (routeTable);
}
BGPRouteTable::~BGPRouteTable() {

}

BGPRoutePrefix BGPRouteTable::findMatchingPrefix(BGPRoutePrefix const &prefix) {
	// TODO: stubb
	return *routeTable.end();
}

std::list<BGPRoutePrefix> BGPRouteTable::findBestMatches(const BGPRoutePrefix &routes) {
	// TODO: stubb
	return routeTable;
}

Prefix BGPRouteTable::calcNextHop(const Prefix &route) {
	// TODO: stubb
	return *routeTable.begin();
}

