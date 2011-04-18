#ifndef ROUTINGTABLE_HPP_
#define ROUTINGTABLE_HPP_

#include <list>
#include "RoutingTableException.hpp"

template<typename R>
class RoutingTable {
public:
	RoutingTable() {};
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
		// TODO: how can man be sure about template's class hierarchy?
//		std::list<R>::iterator routeIt;
//		for (routeIt = routeTable.begin(); routeIt != routeTable.end(); routeIt++) {
//			if (routeIt == route) {
//				return true;
//			}
//		}
		return false;
	}

	virtual Prefix calcNextHop(const Prefix &DestAddr) =0;

protected:
	std::list<R> routeTable;
};
#endif /* ROUTINGTABLE_HPP_ */
