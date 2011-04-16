// $Id$
/**
 * @file BGP_Timer.hpp
 *
 * Definitions for the BGP timers ConnectRetryTimer,
 * HoldTimer and KeepAliveTimer.
 *
 * @brief BGP timers.
 *
 * @author Pekka Ranta
 *
 */
// $Log$

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>

/**
 * ConnectRetryTimer Class. Defines the BGP ConnectRetryTimer.
 */
class ConnectRetryTimer {
	public:
		ConnectRetryTimer(boost::asio::io_service& io, int _connectRetryTime);
		~ConnectRetryTimer();
		void start();
		void join();
		void process();
		void setConnectRetryTime(int _connectRetryTime);
		static const int CONNECTRETRYTIME = 12; /** default initial value for ConnectRetryTimer in seconds */
	private:
		boost::asio::deadline_timer timer_;
		boost::thread thread_;
		int elapsedTime_; /** Amount of time the timer has been running in seconds */
		int connectRetryTime_; /** Time set for the timer */
		void run();
};

/**
 * HoldTimer Class. Defines the BGP HoldTimer.
 */
class HoldTimer {
	public:
		HoldTimer(boost::asio::io_service& io, int _holdTime);
		~HoldTimer();
		void start();
		void join();
		void process();
		static const int HOLDTIME = 9; /** Default initial value for HoldTimer in seconds */
		static const int LARGEHOLDTIME = 24; /** Suggested large value for HoldTimer in secondss */
	private:
		boost::asio::deadline_timer timer_;
		boost::thread thread_;
		int elapsedTime_; /** Amount of time the timer has been running in seconds */
		int holdTime_; /** Time set for the timer */
		void run();
};

/**
 * KeepAliveTimer Class. Defines the BGP KeepAliveTimer.
 */
class KeepAliveTimer {
	public:
		KeepAliveTimer(boost::asio::io_service& io, int _keepAliveTime);
		~KeepAliveTimer();
		void start();
		void join();
		void process();
		static const int KEEPALIVETIME = 3; /** Default initial value for KeepAliveTimer in seconds */
	private:
		boost::asio::deadline_timer timer_;
		boost::thread thread_;
		int elapsedTime_; /** Amount of time the timer has been running in seconds */
		int keepAliveTime_; /** Time set for the timer */
		void run();
};

#endif /* TIMER_HPP_ */
