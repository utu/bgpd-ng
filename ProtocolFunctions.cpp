/*
 * ProtocolFunctions.cpp
 *
 *  Created on: Feb 17, 2011
 *      Author: pebe
 */
#include <iostream>
#include "ProtocolFunctions.h"

	void initializeResources() {
		std::cout << "Initialize BGP resources ja sillee\n"; // Initialize BGP resources
	}
	void releaseResources(); // Release BGP resources
	void completeBGPInit(); // Completes BGP initialization

	void sendOPENMsg( int connection);

	void setConnectRetryCounter(int retries) {
		connectRetryCounter = retries; // Set ConnectRetryCounter to given value
	}

	void startConnectRetryTimer(); // Start the ConnectRetryTimer
	void stopConnectRetryTimer(); // Stop the ConnectRetryTimer
	void setConnectRetryTimer(int retryDelay); // Set ConnectRetryTimer to given value
	bool connectRetryTimerIsRunning(); // returns whether the ConnectRetryTimer is running

	void setHoldTimer();

	bool initTCPConnection(); // Initialize TCP Connection
	bool dropTCPConnection( int connection ); // Drop TCP Connection
	// listen TCP Connections !?

