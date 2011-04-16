/*
 * ProtocolFunctions.hpp
 *
 *  Created on: Feb 17, 2011
 *      Author: pebe
 */

#ifndef PROTOCOLFUNCTIONS_HPP_
#define PROTOCOLFUNCTIONS_HPP_


	void initializeResources(); // Initialize BGP resources
	void releaseResources(); // Release BGP resources
	void completeBGPInit(); // Completes BGP initialization

	void sendOPENMsg();
	void sendNOTIFICATIONMsg();
	void sendKEEPALIVEmsg();
	bool openOK();

	void setConnectRetryCounter(int retries); // Set ConnectRetryCounter to given value

	void startConnectRetryTimer(); // Start the ConnectRetryTimer
	void stopConnectRetryTimer(); // Stop the ConnectRetryTimer
	void setConnectRetryTimer(int retryDelay); // Set ConnectRetryTimer to given value
	bool connectRetryTimerIsRunning(); // returns whether the ConnectRetryTimer is running
	void incrementConnectRetryCounter(); //increments ConnectRetrycounter
	void stopKeepAliveTimer();
	void setKeepAliveTimer(int keepaliveTime);
	void startKeepAliveTimer();
	void stopHoldTimer();
	void setHoldTimer(int holdTime);
	void startHoldTimer();
	bool updateOK();
	void sendUPDATEmsg();

	void setHoldTimer(int holdTime);

	bool initTCPConnection(); // Initialize TCP Connection
	bool dropTCPConnection(); // Drop TCP Connection
	void listenTCPConnections();


#endif /* PROTOCOLFUNCTIONS_HPP_ */
