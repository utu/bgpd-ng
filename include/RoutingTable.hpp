#ifndef ROUTINGTABLE_HPP_
#define ROUTINGTABLE_HPP_

#include <list>
#include "Prefix.hpp"
#include "RoutingTableException.hpp"

template<typename R = Prefix>
class RoutingTable {
public:
	RoutingTable();
	virtual ~RoutingTable() {};

	void clearTable() {
		routeTable.clear();
		// TODO: stub
	}

	bool isEmpty() {
		return routeTable.empty();
	}

	void deletePrefix(const R &prefix) {
		if (not isEmpty()) {
			routeTable.remove(prefix);
		} else {
			throw RoutingTableException(
					std::string(
							"Can't delete the given route. The route does not exist in the table."));
		}
	}

	void addPrefix(R &prefix) {
		routeTable.push_back(prefix);
	}

	bool completePrefixMatch(const R &route) {
//		std::list<R>::iterator routeIt;
//		for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
//			if (routeIt == route) {
//				return true;
//			}
//		}
		return false;
	}

	/* Calculates the best matches for the given route prefix.
	 */
	virtual std::list<R> findBestMatches(const R &route) =0;

	/* Given the destination BGPRoutePrefix, this function calculates the
	 * most appropriate NextHop prefix from the routing table.
	 * The decision criteria are:
	 *
	 * 1) If there is a complete prefix match in the routing list.
	 * 2) If no perfect match is found, we search for best match with shortest AS path.
	 * 3) Prefer static routes.
	 */
	virtual R calcNextHop(const Prefix &DestAddr) =0;

protected:
	std::list<R> routeTable;
};
#endif /* ROUTINGTABLE_HPP_ */
