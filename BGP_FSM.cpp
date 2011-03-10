// $Id$
/**
 * @file BGP_FSM.hpp
 *
 * @brief BGP State Machine.
 *
 * @author Pekka Ranta
 *
 * @version
 *
 */
// $Log$
#include <iostream>
#include "BGP_FSM.hpp" // BGP State Machine

/*
 * BGP_FSM
 */
BGP_FSM::BGP_FSM() :
		m_state(1),
		m_connectRetryCounter(0),
		m_connectRetryTimer(m_ioService,ConnectRetryTimer::CONNECTRETRYTIME),
		m_holdTimer(m_ioService,HoldTimer::HOLDTIME),
		m_keepAliveTimer(m_ioService,KeepAliveTimer::KEEPALIVETIME)
		{};
BGP_FSM::~BGP_FSM() {};

void BGP_FSM::start() {
	m_thread = boost::thread(&BGP_FSM::run, this);
};

void BGP_FSM::join() {
	m_thread.join();
};

void BGP_FSM::run() {
	std::cout << "FSM Thread" << std::endl;
	this->initiate();
};

void BGP_FSM::inputEvent(const event_base_type & evt ) {
	this->process_event(evt);
};

void BGP_FSM::startConnectRetryTimer() {
	m_connectRetryTimer.start();
	m_connectRetryTimer.join();
};

void BGP_FSM::setConnectRetryTime(int connectRetryTime) {
	m_connectRetryTime = connectRetryTime;
};
void BGP_FSM::startHoldTimer() {
	m_holdTimer.start();
	m_holdTimer.join();
};

void BGP_FSM::startKeepAliveTimer() {

	m_keepAliveTimer.start();
	m_keepAliveTimer.join();
};
void BGP_FSM::setKeepAliveTime(int keepAliveTime) {
	m_keepAliveTime = keepAliveTime;
};
void BGP_FSM::runIOService() {
	m_ioService.run();
};

// END BGP STATE MACHINE

