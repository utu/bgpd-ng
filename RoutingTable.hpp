/*
 * RoutingTable.hpp
 *
 *  Created on: 26.2.2011
 *      Author: noora
 */

#ifndef ROUTINGTABLE_HPP_
#define ROUTINGTABLE_HPP_

#include <list>
#include "BGPRoutePrefix.hpp"
#include "RoutePrefix.hpp"

class RoutingTable
{
public:
	//Init RoutingTable
	RoutingTable();


	// Delete given prefix from the table
	void deletePrefix(RoutePrefix &prefix);


	// Add new prefix to the table
	void addPrefix(RoutePrefix &prefix);


	// Provides information about the emptiness.
	bool isEmpty();


	// Returns the position of the given prefix in the array.
	int getRouteTableIndex(RoutePrefix &prefix);


	/* Does a given prefix match some prefix in the table?
	 * Match requires, that all the parameters in RoutePrefix match.
	 * If a complete match is found, the function returns the corres-
	 * ponding BGPRoutePrefix.
	 */
	BGPRoutePrefix findMatchingPrefix(RoutePrefix &prefix);


	/*
	 * Calculates the best matches for the given route prefix.
	 */
	RoutePrefix* findBestMatches(RoutePrefix &route);


	/*
	 *  Calculates the longest prefix match for the given route
	 *  and the routes in the table.
	 */
	int findLongestMatchLength(RoutePrefix &route);


	/*
	 * Searches for the shortest AS_Path and returns the length of it.
	 */
	int findShortestASPathLength();


	/*
	 * Filters all such paths from the given route list that
	 * have the shortest AS_PATH length
	 */
	RoutePrefix* filterShortestASPaths(RoutePrefix &routes);


	/*
	 * Given the destination BGPRoutePrefix, this function calculates the
	 * most appropriate NextHop prefix from the routing table.
	 * The decision criteria are:
	 *
	 * 1) If there is a complete prefix match in the routing list, then
	 * 	  we forward the packet there.
	 *
	 * 2) If no perfect match is found, we search for the most exact match.
	 * 	  If there are more than one of them, the next comparison is made
	 *    between the AS_Path lengths.
	 *
	 * 3) If there are as specific prefixes with same AS_Path length, then
	 * 	  first choose the static route. If none of the routes is static,
	 * 	  then check which of the routes was added to the list first. If
	 * 	  there are still routes with same parameters, then choose the
	 *	  route that is first in the list of the found prefixes.
	 */
	BGPRoutePrefix calcNextHop(RoutePrefix &DestAddr);

	/*
	 * Does the routing table contain a complete match with the given RoutePrefix?
	 */
	bool completePrefixMatch(RoutePrefix &route);

	/*
	 * Clears the whole routing table.
	 */
	void clearTable();

private:
	std::list<RoutePrefix> routeTable;
	std::list<RoutePrefix>::iterator routeIt;
	static const int MAX_SIZE;
	int last_index;
};
#endif /* ROUTINGTABLE_HPP_ */
