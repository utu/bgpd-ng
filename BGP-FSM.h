/*
 * BGP-FSM.h
 *
 *  Created on: Feb 9, 2011
 *      Author: pebe
 */

#ifndef BGPFSM_H_
#define BGPFSM_H_

#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/mpl/list.hpp>

namespace sc = boost::statechart;
namespace mpl = boost::mpl;

// BGP States
struct State; // yleinen tila
struct Idle;
struct Connect;
struct Active;
struct OpenSent;
struct OpenConfirm;
struct Established;

// Administrative Events
struct ManualStart : sc::event< ManualStart > {};
struct ManualStop : sc::event< ManualStop > {};

// Timer Events
struct ConnectRetryTimer_Expires : sc::event< ConnectRetryTimer_Expires > {};
struct HoldTimer_Expires : sc::event< HoldTimer_Expires > {};
struct KeepaliveTimer_Expires : sc::event< KeepaliveTimer_Expires > {};

// TCP Connection-Based Events
struct Tcp_CR_Acked : sc::event< Tcp_CR_Acked > {};
struct TcpConnectionConfirmed : sc::event< TcpConnectionConfirmed > {};
struct TcpConnectionFails : sc::event< TcpConnectionFails > {};

// BGP Message-Based Events
struct BGPOpen : sc::event< BGPOpen > {};
struct BGPHeaderErr : sc::event< BGPHeaderErr > {};
struct BGPOpenMsgErr : sc::event< BGPOpenMsgErr > {};
struct NotifMsgVerErr : sc::event< NotifMsgVerErr > {};
struct NotifMsg : sc::event< NotifMsg > {};
struct KeepAliveMsg : sc::event< KeepAliveMsg > {};
struct UpdateMsg : sc::event< UpdateMsg > {};
struct UpdateMsgErr : sc::event< UpdateMsgErr > {};


struct FSM : sc::state_machine< FSM, Idle  > {};

// STATE
struct State : sc::simple_state< State, FSM >
{
	State() { std::cout << "Entering State...\n"; } // entry
	~State() { std::cout << "Leaving State...\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStart >,
		sc::custom_reaction< ManualStop >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStart & );
	sc::result react( const ManualStop & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};// END STATE

// IDLE STATE
struct Idle : sc::simple_state< Idle, FSM >
{
	Idle() { std::cout << "Entering State IDLE...\n"; } // entry
	~Idle() { std::cout << "Leaving State IDLE...\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStart >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStart & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};// END IDLE STATE

struct Connect : sc::simple_state< Connect, FSM >
{
	Connect() { std::cout << "Entering state CONNECT...\n"; } // entry
	~Connect() { std::cout << "Leaving state CONNECT...\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStop >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStart & );
	sc::result react( const ManualStop & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};


struct Active : sc::simple_state< Active, FSM >
{
	Active() { std::cout << "Entering state ACTIVE...\n"; } // entry
	~Active() { std::cout << "Leaving state ACTIVE...\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStop >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStop & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};

struct OpenSent : sc::simple_state< OpenSent, FSM >
{
	OpenSent() { std::cout << "Entering state OPENSENT...\n"; } // entry
	~OpenSent() { std::cout << "Leaving state OPENSENT...\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStart >,
		sc::custom_reaction< ManualStop >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStart & );
	sc::result react( const ManualStop & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};
/*
struct OpenConfirm : sc::simple_state< OpenConfirm, FSM >
{
	OpenConfirm() { std::cout << "Entering state OPENCONFIRM...\n"; } // entry
	~OpenConfirm() { std::cout << "Leaving state OPENCONFIRM\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStart >,
		sc::custom_reaction< ManualStop >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStart & );
	sc::result react( const ManualStop & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};

struct Established : sc::simple_state< Established, FSM >
{
	Established() { std::cout << "Entering state ESTABLISHED...\n"; } // entry
	~Established() { std::cout << "Leaving state ESTABLISHED...\n"; } // exit
	typedef mpl::list<
		sc::custom_reaction< ManualStart >,
		sc::custom_reaction< ManualStop >,
		sc::custom_reaction< ConnectRetryTimer_Expires >,
		sc::custom_reaction< HoldTimer_Expires >,
		sc::custom_reaction< KeepaliveTimer_Expires >,
		sc::custom_reaction< Tcp_CR_Acked >,
		sc::custom_reaction< TcpConnectionConfirmed >,
		sc::custom_reaction< TcpConnectionFails >,
		sc::custom_reaction< BGPOpen >,
		sc::custom_reaction< BGPHeaderErr >,
		sc::custom_reaction< BGPOpenMsgErr >,
		sc::custom_reaction< NotifMsgVerErr >,
		sc::custom_reaction< NotifMsg >,
		sc::custom_reaction< KeepAliveMsg >,
		sc::custom_reaction< UpdateMsg >,
		sc::custom_reaction< UpdateMsgErr > > reactions;
	sc::result react( const ManualStart & );
	sc::result react( const ManualStop & );
	sc::result react( const ConnectRetryTimer_Expires & );
	sc::result react( const HoldTimer_Expires & );
	sc::result react( const KeepaliveTimer_Expires & );
	sc::result react( const Tcp_CR_Acked & );
	sc::result react( const TcpConnectionConfirmed & );
	sc::result react( const TcpConnectionFails & );
	sc::result react( const BGPOpen & );
	sc::result react( const BGPHeaderErr & );
	sc::result react( const BGPOpenMsgErr & );
	sc::result react( const NotifMsgVerErr & );
	sc::result react( const NotifMsg & );
	sc::result react( const KeepAliveMsg & );
	sc::result react( const UpdateMsg & );
	sc::result react( const UpdateMsgErr & );
};*/

#endif /* BGPFSM_H_ */
