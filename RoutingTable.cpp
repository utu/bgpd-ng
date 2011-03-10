/*
 * RoutingTable.cpp
 *
 *  Created on: 26.2.2011
 *      Author: noora
 */

#include "RoutingTable.hpp"
#include "BGPRoutePrefix"
#include "BGPRoute"

RoutingTable::RoutingTable()

{
	RoutingTable::routeTable = NULL;
	RoutingTable::routeTable = new RoutePrefix[RoutingTable::MAX_SIZE];
	RoutingTable::last_index = 0;
}

RoutingTable::clearTable()
{
	delete [] RoutingTable::routeTable;
	RoutingTable::routeTable = NULL;

	RoutingTable::last_index = 0;
}

bool RoutingTable::isEmpty()
{
	if(RoutingTable::last_index ==0){
		return true;
	}

	else return false;
}

int RoutingTable::getRouteTableIndex(RoutePrefix prefix)
{
	int i = 0;

	while ( i <= RoutingTable::last_index)
	{
		if(prefix.matches(RoutingTable::routeTable[i]))
		{
			return i;
		}

		else ++i;
	}

	return i;
}

RoutingTable::deletePrefix(RoutePrefix prefix)
{
	if(not RoutingTable::isEmpty() )

	{
		int index = RoutingTable::getRouteTableIndex(prefix);

		// index > 0 ==> There is a match, so deletion can be made.
		if(index > 0)
			{

			RoutingTable::routeTable[index] = NULL;

			for(int i = index; i < RoutingTable::last_index; ++i)
					{
						RoutingTable::routeTable[i] = RoutingTable::routeTable[i+1];
					}

			RoutingTable::last_index = RoutingTable::last_index - 1;

			}
		else throw RoutingTableEmptyException();
	}

}

void RoutingTable::addPrefix(RoutePrefix prefix)
{
	RoutingTable::routeTable[last_index + 1] = prefix;
	RoutingTable::last_index = last_index + 1;
}

BGPRoutePrefix RoutingTable::findMatchingPrefix(RoutePrefix prefix)
{
	int i = 0;

	while(i <= RoutingTable::last_index)
		{
			if(RoutingTable::routeTable[i].matches(route))
			{
				return i;
			}

			else ++i;
		}

	return 0;


}

bool RoutingTable::completePrefixMatch(RoutePrefix route)
{
	if(RoutingTable::findMatchingPrefix(route)>0)
	{
		return true;
	}

	else return false;
}

int findLongestMatchLength(RoutePrefix route)
{
	int longestMatch = 0;

	for(int i = 0; i <= RoutingTable::last_index; ++i)
	{
		if( countMatchingBits(RoutingTable::routeTable[i],route) > longestMatch)
		{
			longestMatch = RoutePrefix::countMatchingBits(RoutingTable::routeTable[i],route);
		}
	}

	return longestMatch;
}

RoutePrefix* RoutingTable::findBestMatches(RoutePrefix route)
{

	RoutePrefix* helpTable = NULL;

	for(int i =0; i <=RoutingTable::last_index; ++i)
	{
		if(RoutingTable::countMatchingBits(RoutingTable::routeTable[i],route) == RoutingTable::findLongestMatchLength(route))
		{
			helpTable[i] = RoutingTable::routeTable[i];
		}
	}

	return helpTable;

}

BGPRoutePrefix RoutingTable::calcNextHop(BGPRoutePrefix route)
{
	RoutePrefix* nextRouteCandidates = NULL;

	//Criteria 1: complete match found.
	if(RoutingTable::completePrefixMatch(route))
	{
		return RoutingTable::findMatchingPrefix(route);
	}

	// Now do the decision due to the second and third criteria.

	nextRouteCandidates = RoutingTable::findBestMatches(route);


}
