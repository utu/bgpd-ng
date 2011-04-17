#ifndef BGPROUTETABLE_HPP_
#define BGPROUTETABLE_HPP_

#include <list>
#include "BGPRoutePrefix.hpp"
#include "RoutePrefix.hpp"
#include "RoutingTable.hpp"

class BGPRouteTable: public RoutingTable<BGPRoutePrefix> {
public:
	BGPRouteTable();
	~BGPRouteTable();

	/* Does a given prefix match some prefix in the table?
	 * Match requires, that all the parameters in BGPRoutePrefix match.
	 * If a complete match is found, the function returns the corres-
	 * ponding BGPRoutePrefix.
	 */
	BGPRoutePrefix findMatchingPrefix(BGPRoutePrefix const &prefix);

	/* Filters all such paths from the given route list that
	 * have the shortest AS_PATH length
	 */
	std::list<BGPRoutePrefix> findBestMatches(const BGPRoutePrefix &route);

	BGPRoutePrefix calcNextHop(const Prefix &DestAddr);
};
#endif /* ROUTINGTABLE_HPP_ */
