// $Id$
/**
 * @file BGP_Timer.cpp
 *
 * Function definitions for the BGP timers.
 *
 * @brief BGP timers' function definitions.
 *
 * @author Pekka Ranta
 *
 */
// $Log$

#include <iostream>
#include "BGP_Timer.hpp"

/*
 * ConnectRetryTimer
 */
ConnectRetryTimer::ConnectRetryTimer(boost::asio::io_service& io, int _connectRetryTime) :
	timer_(io, boost::posix_time::seconds(1)), elapsedTime_(0), connectRetryTime_(_connectRetryTime) {
}
ConnectRetryTimer::~ConnectRetryTimer() {}
void ConnectRetryTimer::start() {
	thread_ = boost::thread(&ConnectRetryTimer::run, this);
}
void ConnectRetryTimer::join() {
	thread_.join();
}
void ConnectRetryTimer::run() {
	timer_.async_wait(boost::bind(&ConnectRetryTimer::process, this));
}
void ConnectRetryTimer::process() {
	if (elapsedTime_ < connectRetryTime_) {
    std::cout << "ConnectRetryTimer: " << connectRetryTime_-elapsedTime_ << "s\n";
    ++elapsedTime_;
    timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
    timer_.async_wait(boost::bind(&ConnectRetryTimer::process, this));
	}
	else {
		std::cout << "ConnectRetryTimer expired." << std::endl;
	}
}
void ConnectRetryTimer::setConnectRetryTime(int _connectRetryTime) {
	connectRetryTime_ = _connectRetryTime;
}
/*
 * HoldTimer
 */
HoldTimer::HoldTimer(boost::asio::io_service& io, int _holdTime) :
	timer_(io, boost::posix_time::seconds(1)), elapsedTime_(0), holdTime_(_holdTime) { }

HoldTimer::~HoldTimer() {}

void HoldTimer::start() {
	thread_ = boost::thread(&HoldTimer::run, this);
}
void HoldTimer::join() {
	thread_.join();
}
void HoldTimer::run() {
	timer_.async_wait(boost::bind(&HoldTimer::process, this));
}
void HoldTimer::process() {
	if (elapsedTime_ < holdTime_) {
    std::cout << "Holdtimer: " << holdTime_-elapsedTime_ << "s\n";
    ++elapsedTime_;
    timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
    timer_.async_wait(boost::bind(&HoldTimer::process, this));
	}
	else {
		std::cout << "HoldTimer expired." << std::endl;
	}
}
/*
 * KeepAliveTimer
 */
KeepAliveTimer::KeepAliveTimer(boost::asio::io_service& io, int _keepAliveTime) :
	timer_(io, boost::posix_time::seconds(1)), elapsedTime_(0), keepAliveTime_(_keepAliveTime) { }
KeepAliveTimer::~KeepAliveTimer() {}
void KeepAliveTimer::process() {
	if (elapsedTime_ < keepAliveTime_) {
		std::cout << "KeepAlivetimer: " << keepAliveTime_-elapsedTime_ << "s\n";
    ++elapsedTime_;
    timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
    timer_.async_wait(boost::bind(&KeepAliveTimer::process, this));
	}
	else {
		std::cout << "KeepAliveTimer expired." << std::endl;
	}
}
void KeepAliveTimer::start() {
	thread_ = boost::thread(&KeepAliveTimer::run, this);
}
void KeepAliveTimer::join() {
	thread_.join();
}
void KeepAliveTimer::run() {
	timer_.async_wait(boost::bind(&KeepAliveTimer::process, this));
}
