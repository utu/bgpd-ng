/*
 * ProtocolFunctions.h
 *
 *  Created on: Feb 17, 2011
 *      Author: pebe
 */

#ifndef PROTOCOLFUNCTIONS_H_
#define PROTOCOLFUNCTIONS_H_

	int state; // Current state id
	int connectRetryCounter; // number of connect retries
	struct connectRetryTimer; // delay for connect retry
	int connectRetryTime; // given
	struct HoldTimer;
	int holdTime;
	int keepAliveTime;


	void initializeResources(); // Initialize BGP resources
	void releaseResources(); // Release BGP resources
	void completeBGPInit(); // Completes BGP initialization

	void sendOPENMsg( int connection);

	void setConnectRetryCounter(int retries); // Set ConnectRetryCounter to given value

	void startConnectRetryTimer(); // Start the ConnectRetryTimer
	void stopConnectRetryTimer(); // Stop the ConnectRetryTimer
	void setConnectRetryTimer(int retryDelay); // Set ConnectRetryTimer to given value
	bool connectRetryTimerIsRunning(); // returns whether the ConnectRetryTimer is running

	void setHoldTimer();

	bool initTCPConnection(); // Initialize TCP Connection
	bool dropTCPConnection( int connection ); // Drop TCP Connection
	// listen TCP Connections !?


#endif /* PROTOCOLFUNCTIONS_H_ */
