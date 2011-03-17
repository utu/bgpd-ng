/*
 * RoutingTable.cpp
 *
 *  Created on: 26.2.2011
 *      Author: noora
 */

#include "RoutingTable.hpp"
#include "RoutingTableException.hpp"
#include "RoutingTableEmptyExecption.hpp"

const int RoutingTable::MAX_SIZE = 100;

RoutingTable::RoutingTable() :
	last_index(0) {
	routeTable = new RoutePrefix[MAX_SIZE];
}

void RoutingTable::clearTable() {
	delete[] routeTable;
	last_index = 0;
}

bool RoutingTable::isEmpty() {
	if (last_index == 0) {
		return true;
	}

	else
		return false;
}

int RoutingTable::getRouteTableIndex(RoutePrefix &prefix) {
	int i = 0;

	while (i <= last_index) {
		if (prefix.matches(routeTable[i])) {
			return i;
		}

		else
			++i;
	}

	return i;
}

void RoutingTable::deletePrefix(RoutePrefix &prefix) {
	if (not isEmpty())

	{
		int index = getRouteTableIndex(prefix);

		// index > 0 ==> There is a match, so deletion can be made.
		if (index > 0) {

			for (int i = index; i < last_index; ++i) {
				routeTable[i] = routeTable[i + 1];
			}

			last_index = last_index - 1;

		}

		else
			throw RoutingTableException(
					"Can't delete the given route. The route does not exist in the table.");
	}

	else
		throw RoutingTableException(
				"Can't delete the given route. The routing table is already empty.");
}

void RoutingTable::addPrefix(RoutePrefix &prefix) {
	routeTable[last_index + 1] = prefix;
	last_index = last_index + 1;
}

bool RoutingTable::completePrefixMatch(RoutePrefix &route) {

	// FIXME: Could you clarify this part? What index i should traverse through?
//	if (countMatchingBits(route, routeTable[i]) == 32) {
//		return true;
//	}
//
//	else
		return false;
}

int RoutingTable::findLongestMatchLength(RoutePrefix &route) {
	int longestMatch = 0;

	// FIXME: C++ is a bit more tricky. One should use STL containers in here...
//	for (int i = 0; i <= routeTable; ++i) {
//		if (!isEmpty()) {
//			longestMatch = RoutePrefix::countMatchingBits(routeTable[i], route);
//		}
//
//		else
//			throw RoutingTableException(
//					"Cannot calculate longest match length. Routing table is empty.");
//	}

	return longestMatch;
}

RoutePrefix* RoutingTable::findBestMatches(RoutePrefix &route) {

	RoutePrefix* helpTable = NULL;

	for (int i = 0; i <= last_index; ++i) {
		if (countMatchingBits(routeTable[i], route) == findLongestMatchLength(
				route)) {
			helpTable[i] = routeTable[i];
		}
	}

	return helpTable;

}

int RoutingTable::findShortestASPathLength() {
	// Suppose that the shortest is in the first position.
	int shortest = routeTable[0].getASPathLength();
	int i = 1;

	//Check whether there exist any shorter ones.
	while (i < last_index) {

		if (shortest > routeTable[i].getASPathLength()) {
			shortest = routeTable[i].getASPathLength();
		}

		++i;

	}

	return shortest;
}

RoutePrefix* RoutingTable::filterShortestASPaths(RoutePrefix &routes)

{

	int shortest = findShortestASPathLength();
	RoutePrexix* listOfShortest = NULL;

	int i = 0;
	int j = 0;

	while (i < last_index) {

		if (routes[i].getASPathLength() == shortest) {
			listofShortest[j] = routes[i];
			++j;
		}
		++i;
	}

	return listOfShortest;
}

BGPRoutePrefix RoutingTable::calcNextHop(RoutePrefix &route) {

	RoutePrefix* nextRouteCandidates = NULL;

	//Criteria 1: complete match found.
	if (completePrefixMatch(route)) {
		return findMatchingPrefix(route);
	}

	else {

		nextRouteCandidates = filterShortestASPaths(nextRouteCandidates);

		/*
		 * Now do the decision due to the second and third criteria.
		 * First find the best matching prexises. There is at least one
		 * such route, since we first calculate the length of the best
		 * match and after it we filter the routes with the same prefix.
		 */

		nextRouteCandidates = findBestMatches(route);

		/*
		 * Criterion 2: Filter the routes with shortest AS_PATH parameter
		 *
		 * Again, we first calculate the length of the shortest AS_PATH, after
		 * which we filter the routes with same AS_PATH length. Therefore
		 * there exists at least one route in the nextRouteCandidates.
		 */

		//There is only one item in the list.
		if (nextRouteCandidates[1] == NULL) {
			return nextRouteCandidates[0];
		}

		// There are more items --> selection by criterion 3!
		else {
			int i = 0;

			// Return the static route, if one exists.
			while (nextRouteCandidates[i] != NULL) {
				if (nextRouteCandidates[i].isStatic()) {
					return nextRouteCandidates[i];
				}
				++i;
			}

			/*
			 * If no static route exists, return the first item in the nextRouteCandidate-list:
			 * Firstly, it is the best matching route from the routeList[]. Secondly, if the adding times
			 * of these members is compared, the first item of nextRouteCandidates[] will be the one that
			 * have been added to the routeList[] first (i.e. before the latter members).
			 */
			return nextRouteCandidates[0];
		}
	}
}

int RoutingTable::countMatchingBits(RoutePrefix &route1, RoutePrefix &route2) {

	int counter = 0;

	unsigned long int route1Bit = ConvertToBits(route1);
	unsigned long int route2Bit = ConvertToBits(route2);

	unsigned long int routesXorred = route1Bit ^ Route2Bit;

	while (routeXorred) {

		++counter;

		routeXorred = (routeXorred - 1) & routeXorred;
	}

	return counter;
}

