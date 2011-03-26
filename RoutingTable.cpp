/*
 * RoutingTable.cpp
 *
 *  Created on: 26.2.2011
 *      Author: noora
 */

#include <list>
#include "RoutingTable.hpp"
#include "RoutingTableException.hpp"
#include "RoutingTableEmptyExecption.hpp"

RoutingTable::RoutingTable() {
}

void RoutingTable::clearTable() {
	routeTable.clear();

}

bool RoutingTable::isEmpty() {
	return routeTable.empty();
}

void RoutingTable::deletePrefix(RoutePrefix &prefix) {
	if (not isEmpty()) {
		routeTable.remove(prefix);
	} else {
		throw RoutingTableException(
				"Can't delete the given route. The route does not exist in the table.");
	}
}

void RoutingTable::addPrefix(RoutePrefix &prefix) {
	routeTable.push_back(prefix);
}

int RoutingTable::findLongestMatchLength(RoutePrefix &route) {
	int longestMatch = 0;
	std::list<RoutePrefix>::iterator routeIt;

	// FIXME: C++ is a bit more tricky. One should use STL containers in here. Size of table is how much it consumes memory.
	if (!isEmpty()) {
		for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
			longestMatch = RoutePrefix::countMatchingBits(*routeIt, route);
		}
	} else {
		throw RoutingTableException(
				"Cannot calculate longest match length. Routing table is empty.");
	}
	return longestMatch;
}

std::list<RoutePrefix>* RoutingTable::findBestMatches(RoutePrefix &route) {

	std::list<RoutePrefix> *helpTable = new std::list<RoutePrefix>();
	std::list<RoutePrefix>::iterator routeIt;

	for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {

		if (RoutePrefix::countMatchingBits(*routeIt, route)
				== findLongestMatchLength(route)) {
			helpTable->push_back(*routeIt);
		}
	}
	return helpTable;

}

int RoutingTable::findShortestASPathLength() {
	// Suppose that the shortest is in the first position.
	RoutePrefix tmp = *routeTable.begin();
	int shortest = tmp.getASPathLength();

	std::list<RoutePrefix>::iterator routeIt;

	//Check whether there exist any shorter ones.
	for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
		if (shortest > routeIt->getASPathLength()) {
			shortest = routeIt->getASPathLength();
		}
	}

	return shortest;
}

std::list<RoutePrefix>* RoutingTable::filterShortestASPaths(RoutePrefix &routes) {

	int shortest = findShortestASPathLength();
	std::list<RoutePrefix> *los = new std::list<RoutePrefix>();
	std::list<RoutePrefix>::iterator routeIt;

	for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
		if (routeIt->getASPathLength() == shortest) {
			los->push_back(*routeIt);
		}
	}
	return los;
}

bool RoutingTable::completePrefixMatch(RoutePrefix &route) {
	std::list<RoutePrefix>::iterator routeIt;

	for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
		if (routeIt->matches(route)) {
			return true;
		}
	}

	return false;
}

BGPRoutePrefix * RoutingTable::calcNextHop(RoutePrefix &route) {

	std::list<RoutePrefix> * best;
	std::list<RoutePrefix> * shorter;

	//Criteria 1: complete match found.

	if (completePrefixMatch(route)) {
		return findMatchingPrefix(route);
	} else {

		/*
		 * Now do the decision due to the second and third criteria.
		 * First find the best matching prefixes. There is at least one
		 * such route, since we first calculate the length of the best
		 * match and after it we filter the routes with the same prefix.
		 */

		best = findBestMatches(route);

		/*
		 * Criterion 2: Filter the routes with shortest AS_PATH parameter
		 *
		 * Again, we first calculate the length of the shortest AS_PATH, after
		 * which we filter the routes with same AS_PATH length. Therefore
		 * there exists at least one route in the nextRouteCandidates.
		 */

		//There is only one item in the list.
		if (best->size() == 1) {
			return *best->begin();
		}

		// There are more items --> selection by criterion 3!
		else {
			shorter = filterShortestASPaths(*best);

			int i = 0;

			// Return the static route, if one exists.
			while (shoreter.length() > 0) {
				if (shorter->isStatic()) {
					return *shorer;
				}
				shorter++;
			}

			/*
			 * If no static route exists, return the first item in the nextRouteCandidate-list:
			 * Firstly, it is the best matching route from the routeList[]. Secondly, if the adding times
			 * of these members is compared, the first item of nextRouteCandidates[] will be the one that
			 * have been added to the routeList[] first (i.e. before the latter members).
			 */
			return shorter.begin();
		}
	}
}

