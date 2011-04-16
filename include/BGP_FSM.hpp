// $Id$
/**
 * @file BGP_FSM.hpp
 *
 * @brief BGP State Machine Definion.
 *
 * @author Pekka Ranta
 *
 */
// $Log$

#ifndef BGPFSM_HPP_
#define BGPFSM_HPP_

#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/mpl/list.hpp>
#include <boost/thread.hpp>
#include <boost/timer.hpp>

#include "BGP_Functions.hpp" // BGP Functions
#include "BGP_Timer.hpp" // BGP Timer Functions

namespace sc = boost::statechart;
namespace mpl = boost::mpl;



/**
 * BGPStart Class. Defines a BGP Start Event.
 */
class BGPStart : public sc::event< BGPStart > {
	public:
		static const int EVENT_ID = 1;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPStop Class. Defines a BGP Stop Event.
 */
class BGPStop : public sc::event< BGPStop > {
	public:
	BGPStop() {
		std::cout << "BGPStop Event" << std::endl;
	}
		static const int EVENT_ID = 2;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a BGP Transport Connection Open Event.
 */
class BGPTransportConnectionOpen : public sc::event< BGPTransportConnectionOpen > {
	public:
		static const int EVENT_ID = 3;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class BGPTransportConnectionClosed : public sc::event< BGPTransportConnectionClosed > {
	public:
		static const int EVENT_ID = 4;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class BGPTransportConnectionOpenFailed : public sc::event< BGPTransportConnectionOpenFailed > {
	public:
		static const int EVENT_ID = 5;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class BGPTransportFatalError : public sc::event< BGPTransportFatalError > {
	public:
		static const int EVENT_ID = 6;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class ConnectRetryTimerExpired : public sc::event< ConnectRetryTimerExpired > {
	public:
		static const int EVENT_ID = 7;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class HoldTimerExpired : public sc::event< HoldTimerExpired > {
	public:
		static const int EVENT_ID = 8;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class KeepAliveTimerExpired : public sc::event< KeepAliveTimerExpired > {
	public:
		static const int EVENT_ID = 9;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class ReceiveOPENMessage : public sc::event< ReceiveOPENMessage > {
	public:
		static const int EVENT_ID = 10;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class ReceiveKEEPALIVEMessage : public sc::event< ReceiveKEEPALIVEMessage > {
	public:
		static const int EVENT_ID = 11;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class ReceiveUPDATEMessages : public sc::event< ReceiveUPDATEMessages > {
	public:
		static const int EVENT_ID = 12;/**< RFC1771 Compliant Event ID */
};
/**
 * BGPTransportConnectionOpen Class. Defines a Transport Connection Closed Event.
 */
class ReceiveNOTIFICATIONMessage : public sc::event< ReceiveNOTIFICATIONMessage > {
	public:
		static const int EVENT_ID = 13;/**< RFC1771 Compliant Event ID */
};

class Idle; // Forward declaration of the initial state
/**
 * BGP_FSM Class. Defines the Border Gateway Protocol State Machine.
 */
class BGP_FSM : public sc::state_machine< BGP_FSM, Idle  > {
	public:
		BGP_FSM();
		~BGP_FSM();
		void start();
		void join();
		void inputEvent(const event_base_type & evt);
		void startConnectRetryTimer();
		void setConnectRetryTime(int connectRetryTime);
		void startHoldTimer();
		void setHoldTime(int holdTime);
		void startKeepAliveTimer();
		void setKeepAliveTime(int keepAliveTime);
		void runIOService();
		void setLargeHoldTimer();
	private:
		boost::asio::io_service m_ioService; // For timer functions
		void run();
		int m_state; // Current state id
		int m_connectRetryCounter; // number of connect retries
		boost::thread m_thread;
		ConnectRetryTimer m_connectRetryTimer;
		int m_connectRetryTime;
		HoldTimer m_holdTimer;
		int m_holdTime;
		KeepAliveTimer m_keepAliveTimer;
		int m_keepAliveTime;
};

/*
 * Class Idle
 */
class Idle : public sc::simple_state< Idle, BGP_FSM > {
	public:
		Idle(); // entry
		~Idle(); // exit
		typedef mpl::list<
			sc::custom_reaction< BGPStart >,
			sc::custom_reaction< BGPStop >,
			sc::custom_reaction< BGPTransportConnectionOpen >,
			sc::custom_reaction< BGPTransportConnectionClosed >,
			sc::custom_reaction< BGPTransportConnectionOpenFailed >,
			sc::custom_reaction< BGPTransportFatalError >,
			sc::custom_reaction< ConnectRetryTimerExpired >,
			sc::custom_reaction< HoldTimerExpired >,
			sc::custom_reaction< KeepAliveTimerExpired >,
			sc::custom_reaction< ReceiveOPENMessage >,
			sc::custom_reaction< ReceiveKEEPALIVEMessage >,
			sc::custom_reaction< ReceiveUPDATEMessages >,
			sc::custom_reaction< ReceiveNOTIFICATIONMessage > > reactions;
		sc::result react( const BGPStart & );
		sc::result react( const BGPStop & );
		sc::result react( const BGPTransportConnectionOpen & );
		sc::result react( const BGPTransportConnectionClosed & );
		sc::result react( const BGPTransportConnectionOpenFailed & );
		sc::result react( const BGPTransportFatalError & );
		sc::result react( const ConnectRetryTimerExpired & );
		sc::result react( const HoldTimerExpired & );
		sc::result react( const KeepAliveTimerExpired & );
		sc::result react( const ReceiveOPENMessage & );
		sc::result react( const ReceiveKEEPALIVEMessage & );
		sc::result react( const ReceiveUPDATEMessages & );
		sc::result react( const ReceiveNOTIFICATIONMessage & );
		static const int STATE_ID = 1;
};

/*
 * Class Connect
 */
class Connect : public sc::simple_state< Connect, BGP_FSM > {
	public:
		Connect(); // entry
		~Connect(); // exit
	typedef mpl::list<
		sc::custom_reaction< BGPStart >,
		sc::custom_reaction< BGPStop >,
		sc::custom_reaction< BGPTransportConnectionOpen >,
		sc::custom_reaction< BGPTransportConnectionClosed >,
		sc::custom_reaction< BGPTransportConnectionOpenFailed >,
		sc::custom_reaction< BGPTransportFatalError >,
		sc::custom_reaction< ConnectRetryTimerExpired >,
		sc::custom_reaction< HoldTimerExpired >,
		sc::custom_reaction< KeepAliveTimerExpired >,
		sc::custom_reaction< ReceiveOPENMessage >,
		sc::custom_reaction< ReceiveKEEPALIVEMessage >,
		sc::custom_reaction< ReceiveUPDATEMessages >,
		sc::custom_reaction< ReceiveNOTIFICATIONMessage > > reactions;
	sc::result react( const BGPStart & );
	sc::result react( const BGPStop & );
	sc::result react( const BGPTransportConnectionOpen & );
	sc::result react( const BGPTransportConnectionClosed & );
	sc::result react( const BGPTransportConnectionOpenFailed & );
	sc::result react( const BGPTransportFatalError & );
	sc::result react( const ConnectRetryTimerExpired & );
	sc::result react( const HoldTimerExpired & );
	sc::result react( const KeepAliveTimerExpired & );
	sc::result react( const ReceiveOPENMessage & );
	sc::result react( const ReceiveKEEPALIVEMessage & );
	sc::result react( const ReceiveUPDATEMessages & );
	sc::result react( const ReceiveNOTIFICATIONMessage & );
	static const int STATE_ID = 2;
};

/*
 * Class Active
 */
class Active : public sc::simple_state< Active, BGP_FSM > {
	public:
		Active(); // entry
		~Active(); // exit
	typedef mpl::list<
		sc::custom_reaction< BGPStart >,
		sc::custom_reaction< BGPStop >,
		sc::custom_reaction< BGPTransportConnectionOpen >,
		sc::custom_reaction< BGPTransportConnectionClosed >,
		sc::custom_reaction< BGPTransportConnectionOpenFailed >,
		sc::custom_reaction< BGPTransportFatalError >,
		sc::custom_reaction< ConnectRetryTimerExpired >,
		sc::custom_reaction< HoldTimerExpired >,
		sc::custom_reaction< KeepAliveTimerExpired >,
		sc::custom_reaction< ReceiveOPENMessage >,
		sc::custom_reaction< ReceiveKEEPALIVEMessage >,
		sc::custom_reaction< ReceiveUPDATEMessages >,
		sc::custom_reaction< ReceiveNOTIFICATIONMessage > > reactions;
	sc::result react( const BGPStart & );
	sc::result react( const BGPStop & );
	sc::result react( const BGPTransportConnectionOpen & );
	sc::result react( const BGPTransportConnectionClosed & );
	sc::result react( const BGPTransportConnectionOpenFailed & );
	sc::result react( const BGPTransportFatalError & );
	sc::result react( const ConnectRetryTimerExpired & );
	sc::result react( const HoldTimerExpired & );
	sc::result react( const KeepAliveTimerExpired & );
	sc::result react( const ReceiveOPENMessage & );
	sc::result react( const ReceiveKEEPALIVEMessage & );
	sc::result react( const ReceiveUPDATEMessages & );
	sc::result react( const ReceiveNOTIFICATIONMessage & );
	static const int STATE_ID = 3;
};

/*
 * Class OpenSent
 */
class OpenSent : public sc::simple_state< OpenSent, BGP_FSM > {
	public:
		OpenSent(); // entry
		~OpenSent(); // exit
	typedef mpl::list<
		sc::custom_reaction< BGPStart >,
		sc::custom_reaction< BGPStop >,
		sc::custom_reaction< BGPTransportConnectionOpen >,
		sc::custom_reaction< BGPTransportConnectionClosed >,
		sc::custom_reaction< BGPTransportConnectionOpenFailed >,
		sc::custom_reaction< BGPTransportFatalError >,
		sc::custom_reaction< ConnectRetryTimerExpired >,
		sc::custom_reaction< HoldTimerExpired >,
		sc::custom_reaction< KeepAliveTimerExpired >,
		sc::custom_reaction< ReceiveOPENMessage >,
		sc::custom_reaction< ReceiveKEEPALIVEMessage >,
		sc::custom_reaction< ReceiveUPDATEMessages >,
		sc::custom_reaction< ReceiveNOTIFICATIONMessage > > reactions;
	sc::result react( const BGPStart & );
	sc::result react( const BGPStop & );
	sc::result react( const BGPTransportConnectionOpen & );
	sc::result react( const BGPTransportConnectionClosed & );
	sc::result react( const BGPTransportConnectionOpenFailed & );
	sc::result react( const BGPTransportFatalError & );
	sc::result react( const ConnectRetryTimerExpired & );
	sc::result react( const HoldTimerExpired & );
	sc::result react( const KeepAliveTimerExpired & );
	sc::result react( const ReceiveOPENMessage & );
	sc::result react( const ReceiveKEEPALIVEMessage & );
	sc::result react( const ReceiveUPDATEMessages & );
	sc::result react( const ReceiveNOTIFICATIONMessage & );
	static const int STATE_ID = 4;
};

/*
 * Class OpenConfirm
 */
class OpenConfirm : public sc::simple_state< OpenConfirm, BGP_FSM > {
	public:
		OpenConfirm(); // entry
		~OpenConfirm(); // exit
		typedef mpl::list<
			sc::custom_reaction< BGPStart >,
			sc::custom_reaction< BGPStop >,
			sc::custom_reaction< BGPTransportConnectionOpen >,
			sc::custom_reaction< BGPTransportConnectionClosed >,
			sc::custom_reaction< BGPTransportConnectionOpenFailed >,
			sc::custom_reaction< BGPTransportFatalError >,
			sc::custom_reaction< ConnectRetryTimerExpired >,
			sc::custom_reaction< HoldTimerExpired >,
			sc::custom_reaction< KeepAliveTimerExpired >,
			sc::custom_reaction< ReceiveOPENMessage >,
			sc::custom_reaction< ReceiveKEEPALIVEMessage >,
			sc::custom_reaction< ReceiveUPDATEMessages >,
			sc::custom_reaction< ReceiveNOTIFICATIONMessage > > reactions;
		sc::result react( const BGPStart & );
		sc::result react( const BGPStop & );
		sc::result react( const BGPTransportConnectionOpen & );
		sc::result react( const BGPTransportConnectionClosed & );
		sc::result react( const BGPTransportConnectionOpenFailed & );
		sc::result react( const BGPTransportFatalError & );
		sc::result react( const ConnectRetryTimerExpired & );
		sc::result react( const HoldTimerExpired & );
		sc::result react( const KeepAliveTimerExpired & );
		sc::result react( const ReceiveOPENMessage & );
		sc::result react( const ReceiveKEEPALIVEMessage & );
		sc::result react( const ReceiveUPDATEMessages & );
		sc::result react( const ReceiveNOTIFICATIONMessage & );
		static const int STATE_ID = 5;
};

/*
 * Class Established
 */
class Established : public sc::simple_state< Established, BGP_FSM > {
	public:
		Established(); // entry
		~Established(); // exit
		typedef mpl::list<
			sc::custom_reaction< BGPStart >,
			sc::custom_reaction< BGPStop >,
			sc::custom_reaction< BGPTransportConnectionOpen >,
			sc::custom_reaction< BGPTransportConnectionClosed >,
			sc::custom_reaction< BGPTransportConnectionOpenFailed >,
			sc::custom_reaction< BGPTransportFatalError >,
			sc::custom_reaction< ConnectRetryTimerExpired >,
			sc::custom_reaction< HoldTimerExpired >,
			sc::custom_reaction< KeepAliveTimerExpired >,
			sc::custom_reaction< ReceiveOPENMessage >,
			sc::custom_reaction< ReceiveKEEPALIVEMessage >,
			sc::custom_reaction< ReceiveUPDATEMessages >,
			sc::custom_reaction< ReceiveNOTIFICATIONMessage > > reactions;
		sc::result react( const BGPStart & );
		sc::result react( const BGPStop & );
		sc::result react( const BGPTransportConnectionOpen & );
		sc::result react( const BGPTransportConnectionClosed & );
		sc::result react( const BGPTransportConnectionOpenFailed & );
		sc::result react( const BGPTransportFatalError & );
		sc::result react( const ConnectRetryTimerExpired & );
		sc::result react( const HoldTimerExpired & );
		sc::result react( const KeepAliveTimerExpired & );
		sc::result react( const ReceiveOPENMessage & );
		sc::result react( const ReceiveKEEPALIVEMessage & );
		sc::result react( const ReceiveUPDATEMessages & );
		sc::result react( const ReceiveNOTIFICATIONMessage & );
		static const int STATE_ID = 6;
};

#endif /* BGPFSM_HPP_ */
