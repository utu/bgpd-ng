#ifndef ROUTEWORKER_HPP_
#define ROUTEWORKER_HPP_

#include <set>
#include "BGPRoutePrefix.hpp"
#include "RoutePrefix.hpp"
#include "RIBRouteTable.hpp"
#include "BGPRouteTable.hpp"
#include "RoutePool.hpp"
#include "RoutingTable.hpp"

class RouteWorker {
public:
	RouteWorker(RoutePool &pool);
	~RouteWorker();
	void addRoute(std::set<BGPRoutePrefix> routeset);
	void withdrawRoute(std::set<BGPRoutePrefix> routeset);

private:
	RoutePool rpool;
	RIBRouteTable rib;
	BGPRouteTable bgp;

	void addRoute(const BGPRoutePrefix& route);
	void withdrawRoute(const BGPRoutePrefix& route);
	void calculateTable();
	void updateRIB();
};

#endif
