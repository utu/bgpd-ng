#include "RouteWorker.hpp"
#include "WorkerExeption.hpp"
#include "IpRoute2.hpp"

/* Public methods */
RouteWorker::RouteWorker(RoutePool &pool) :
	rpool(pool) {

}
RouteWorker::~RouteWorker() {

}
void RouteWorker::addRoute(std::set<BGPRoutePrefix> routeset) {
	throw WorkerException("Can't operate. Fall back to static routes.");
}
void RouteWorker::withdrawRoute(std::set<BGPRoutePrefix> routeset) {
	throw WorkerException("Can't operate. Fall back to static routes.");
}

/* Private methods */
void RouteWorker::addRoute(const BGPRoutePrefix& route) {

}
void RouteWorker::withdrawRoute(const BGPRoutePrefix& route) {

}
void RouteWorker::calculateTable() {

}
void RouteWorker::updateRIB() {

}
