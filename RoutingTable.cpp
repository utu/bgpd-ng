/*
 * RoutingTable.cpp
 *
 *  Created on: 26.2.2011
 *      Author: noora
 */

#include "RoutingTable.hpp"
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
	if (RoutingTable::last_index == 0) {
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
	if (not isEmpty()) {
		int index = getRouteTableIndex(prefix);

		// index > 0 ==> There is a match, so deletion can be made.
		if (index > 0) {

			for (int i = index; i < last_index; ++i) {
				routeTable[i] = routeTable[i + 1];
			}

			last_index = last_index - 1;

		} else {
			throw new RoutingTableEmptyException("Le fu.");
		}
	}

}

void RoutingTable::addPrefix(RoutePrefix &prefix) {
	routeTable[last_index + 1] = prefix;
	last_index = last_index + 1;
}

int RoutingTable::findMatchingPrefix(RoutePrefix &prefix) {
	int i = 0;

//FIXME: can't understand this. there's no route declared here
//	while (i <= last_index) {
//		if (routeTable[i].matches(route)) {
//			return i;
//		}
//
//		else
//			++i;
//	}

	return 0;
}

bool RoutingTable::completePrefixMatch(RoutePrefix &route) {
	if (findMatchingPrefix(route) > 0) {
		return true;
	}

	else
		return false;
}

int RoutingTable::findLongestMatchLength(RoutePrefix &route) {
	int longestMatch = 0;

	for (int i = 0; i <= last_index; ++i) {
		if (countMatchingBits(routeTable[i], route) > longestMatch) {
			longestMatch = countMatchingBits(routeTable[i], route);
		}
	}

	return longestMatch;
}

RoutePrefix* RoutingTable::findBestMatches(RoutePrefix &route) {

	RoutePrefix* helpTable;

	for (int i = 0; i <= last_index; ++i) {
		if (countMatchingBits(routeTable[i], route) == findLongestMatchLength(
				route)) {
			helpTable[i] = routeTable[i];
		}
	}

	return helpTable;

}

int RoutingTable::calcNextHop(RoutePrefix &route) {
	RoutePrefix* nextRouteCandidates = NULL;

	//Criteria 1: complete match found.
	if (completePrefixMatch(route)) {
		return findMatchingPrefix(route);
	}

	// Now do the decision due to the second and third criteria.

	nextRouteCandidates = findBestMatches(route);

}

int RoutingTable::countMatchingBits(RoutePrefix &route1, RoutePrefix &route2) {
	// FIXME: dummy
	return 0;
}
