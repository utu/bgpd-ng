// $Id$
/**
 * @file BGP_State.hpp
 *
 * @brief Defines BGP state machine states and their reactions to input events.
 *
 * @author Pekka Ranta
 *
 * @version
 *
 */
// $Log$
#include "BGP_FSM.hpp" // BGP State Machine

/*
 * Class Idle
 */
Idle::Idle() { std::cout << "Entering State IDLE...\n\n"; } // entry
Idle::~Idle() { std::cout << "Leaving State IDLE...\n\n"; } // exit



void startOperations() {

	std::cout << "tehdäänpä tämmösii" << std::endl;
	sleep(3);
	std::cout << "ja tämmösii" << std::endl;
}


/**
 * Reaction for BGPStart input event.
 * Initializes BGP resources.
 *
 * @param[in] BGPStart
 * @return Transition to Connect State
 */
sc::result Idle::react( const BGPStart & ) {
	initializeResources();
	startConnectRetryTimer();
	initTCPConnection();
	return transit< Connect >();
}
sc::result Idle::react( const BGPStop & ) {
	return discard_event();
}
sc::result Idle::react( const BGPTransportConnectionOpen & ) {
	return discard_event();
}
sc::result Idle::react( const BGPTransportConnectionClosed & ) {
	return discard_event();
}
sc::result Idle::react( const BGPTransportConnectionOpenFailed & ) {
	return discard_event();
}
sc::result Idle::react( const BGPTransportFatalError & ) {
	return discard_event();
}
sc::result Idle::react( const ConnectRetryTimerExpired & ) {
	return discard_event();
}
sc::result Idle::react( const HoldTimerExpired & ) {
	return discard_event();
}
sc::result Idle::react( const KeepAliveTimerExpired & ) {
	return discard_event();
}
sc::result Idle::react( const ReceiveOPENMessage & ) {
	return discard_event();
}
sc::result Idle::react( const ReceiveKEEPALIVEMessage & ) {
	return discard_event();
}
sc::result Idle::react( const ReceiveUPDATEMessages & ) {
	return discard_event();
}
sc::result Idle::react( const ReceiveNOTIFICATIONMessage & ) {
	return discard_event();
}
/*
 * Class Connect
 */
Connect::Connect() { std::cout << "Entering state CONNECT...\n\n"; } // entry
Connect::~Connect() { std::cout << "Leaving state CONNECT...\n\n"; } // exit
// BGPStart (Event 1)
sc::result Connect::react( const BGPStart & ) {
	return discard_event();
}
// BGPStop (Event 2)
sc::result Connect::react( const BGPStop & ) {
	releaseResources();
	return transit< Idle >();
}
// BGPStart (Event 3)
sc::result Connect::react( const BGPTransportConnectionOpen & ) {
	completeBGPInit();
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	sendOPENMsg();
	return transit< OpenSent >();
}
sc::result Connect::react( const BGPTransportConnectionClosed & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const BGPTransportConnectionOpenFailed & ) {
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	startConnectRetryTimer();
	return transit< Active >();
}
sc::result Connect::react( const BGPTransportFatalError & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const ConnectRetryTimerExpired & ) {
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	startConnectRetryTimer();
	initTCPConnection();
	return transit< Connect >();
}
sc::result Connect::react( const HoldTimerExpired & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const KeepAliveTimerExpired & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const ReceiveOPENMessage & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const ReceiveKEEPALIVEMessage & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const ReceiveUPDATEMessages & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Connect::react( const ReceiveNOTIFICATIONMessage & ) {
	releaseResources();
	return transit< Idle >();
}
/*
 * Class Active
 */
Active::Active() { std::cout << "Entering state ACTIVE...\n\n"; } // entry
Active::~Active() { std::cout << "Leaving state ACTIVE...\n\n"; } // exit
sc::result Active::react( const BGPStart & ) {
	return discard_event();
}
sc::result Active::react( const BGPStop & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const BGPTransportConnectionOpen & ) {
	completeBGPInit();
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	sendOPENMsg();
	return transit< OpenSent >();
}
sc::result Active::react( const BGPTransportConnectionClosed & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const BGPTransportConnectionOpenFailed & ) {
	dropTCPConnection();
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	startConnectRetryTimer();
	return transit< Active >();
}
sc::result Active::react( const BGPTransportFatalError & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const ConnectRetryTimerExpired & ) {
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	startConnectRetryTimer();
	initTCPConnection();
	return transit< Connect >();
}
sc::result Active::react( const HoldTimerExpired & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const KeepAliveTimerExpired & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const ReceiveOPENMessage & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const ReceiveKEEPALIVEMessage & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const ReceiveUPDATEMessages & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result Active::react( const ReceiveNOTIFICATIONMessage & ) {
	releaseResources();
	return transit< Idle >();
}
/*
 * Class OpenSent
 */
OpenSent::OpenSent() { std::cout << "Entering state OPENSENT...\n\n"; } // entry
OpenSent::~OpenSent() { std::cout << "Leaving state OPENSENT...\n\n"; } // exit
sc::result OpenSent::react( const BGPStart & ) {
	return discard_event();
}
sc::result OpenSent::react( const BGPStop & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const BGPTransportConnectionOpen & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const BGPTransportConnectionClosed & ) {
	dropTCPConnection();
	stopConnectRetryTimer();
	setConnectRetryTimer(120);
	startConnectRetryTimer();
	return transit< Active >();
}
sc::result OpenSent::react( const BGPTransportConnectionOpenFailed & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const BGPTransportFatalError & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result OpenSent::react( const ConnectRetryTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const HoldTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const KeepAliveTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const ReceiveOPENMessage & ) {
	if(openOK()) {
		sendKEEPALIVEmsg();
		return transit< OpenConfirm >();
	}
	else {
		sendNOTIFICATIONMsg();
		return transit< Idle >();
	}
}
sc::result OpenSent::react( const ReceiveKEEPALIVEMessage & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const ReceiveUPDATEMessages & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenSent::react( const ReceiveNOTIFICATIONMessage & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
/*
 * Class OpenConfirm
 */
OpenConfirm::OpenConfirm() { std::cout << "Entering state OPENCONFIRM...\n\n"; } // entry
OpenConfirm::~OpenConfirm() { std::cout << "Leaving state OPENCONFIRM...\n\n"; } // exit
sc::result OpenConfirm::react( const BGPStart & ) {
	return discard_event();
}
sc::result OpenConfirm::react( const BGPStop & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const BGPTransportConnectionOpen & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const BGPTransportConnectionClosed & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const BGPTransportConnectionOpenFailed & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const BGPTransportFatalError & ) {
	releaseResources();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const ConnectRetryTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const HoldTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const KeepAliveTimerExpired & ) {
	stopKeepAliveTimer();
	setKeepAliveTimer(120);
	startKeepAliveTimer();
	return transit< OpenConfirm >();
}
sc::result OpenConfirm::react( const ReceiveOPENMessage & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const ReceiveKEEPALIVEMessage & ) {
	completeBGPInit();
	stopHoldTimer();
	setHoldTimer(120);
	startHoldTimer();
	return transit< Established >();
}
sc::result OpenConfirm::react( const ReceiveUPDATEMessages & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result OpenConfirm::react( const ReceiveNOTIFICATIONMessage & ) {
	dropTCPConnection();
	releaseResources();
	return transit< Idle >();
}
/*
 * Class Established
 */
Established::Established() { std::cout << "Entering state ESTABLISHED...\n\n"; } // entry
Established::~Established() { std::cout << "Leaving state ESTABLISHED...\n\n"; } // exit
sc::result Established::react( const BGPStart & ) {
	return discard_event();
}
sc::result Established::react( const BGPStop & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result Established::react( const BGPTransportConnectionOpen & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result Established::react( const BGPTransportConnectionClosed & ) {
	return discard_event();
}
sc::result Established::react( const BGPTransportConnectionOpenFailed & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result Established::react( const BGPTransportFatalError & ) {
	return discard_event();
}
sc::result Established::react( const ConnectRetryTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result Established::react( const HoldTimerExpired & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result Established::react( const KeepAliveTimerExpired & ) {
	return discard_event();
}
sc::result Established::react( const ReceiveOPENMessage & ) {
	dropTCPConnection();
	releaseResources();
	sendNOTIFICATIONMsg();
	return transit< Idle >();
}
sc::result Established::react( const ReceiveKEEPALIVEMessage & ) {
	stopHoldTimer();
	setHoldTimer(120);
	startHoldTimer();
	return transit< Established >();
}
sc::result Established::react( const ReceiveUPDATEMessages & ) {
	if(updateOK()) {
		sendUPDATEmsg();
		return transit< Established >();
	}
	else {
		sendNOTIFICATIONMsg();
		return transit< Idle >();
	}
}
sc::result Established::react( const ReceiveNOTIFICATIONMessage & ) {
	dropTCPConnection();
	releaseResources();
	return transit< Idle >();
}
