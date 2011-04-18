#ifndef RIBROUTETABLE_HPP_
#define RIBROUTETABLE_HPP_

#include <list>
#include "Prefix.hpp"
#include "RoutePrefix.hpp"
#include "RoutingTable.hpp"

class RIBRouteTable: public RoutingTable<RoutePrefix> {
public:
	RIBRouteTable();
	~RIBRouteTable();
	std::list<RoutePrefix> findBestMatches(const RoutePrefix &route);
	Prefix calcNextHop(const Prefix &DestAddr);
};
#endif /* ROUTINGTABLE_HPP_ */
