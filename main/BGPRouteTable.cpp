#include "BGPRouteTable.hpp"
#include "RoutingTableException.hpp"
#include "RoutingTableEmptyExecption.hpp"

BGPRouteTable::BGPRouteTable() {

}
BGPRouteTable::~BGPRouteTable() {

}

BGPRoutePrefix BGPRouteTable::findMatchingPrefix(BGPRoutePrefix const &prefix) {

}

std::list<BGPRoutePrefix> findBestMatches(const RoutePrefix &routes) {

}

BGPRoutePrefix BGPRouteTable::calcNextHop(const Prefix &route) {

	std::list<BGPRoutePrefix> best;
	std::list<BGPRoutePrefix> shorter;

	std::list<BGPRoutePrefix>::iterator it;
	it = best.begin();

	return *it;
}

