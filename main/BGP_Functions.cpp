// $Id$
/**
 * @file BGP_Functions.hpp
 *
 * @brief Defines dummy BGP functions.
 *
 * @author Pekka Ranta
 *
 */
// $Log$
#include <iostream>
#include "BGP_Functions.hpp"

	void initializeResources() {
		std::cout << "\tinitializeResources()\n\n"; // Initialize BGP resources
	}
	void releaseResources() {
		std::cout << "\treleaseResources()\n\n"; // Release BGP resources
	}
	void completeBGPInit() {
		std::cout << "\tcompleteBGPInit()\n\n"; // Completes BGP initialization
	}

	void sendOPENMsg() {
		std::cout << "\tsendOPENMsg()\n\n";
	}
	void sendNOTIFICATIONMsg() {
		std::cout << "\tsendNOTIFICATIONMsg()\n\n";
	}
	void sendKEEPALIVEmsg() {
		std::cout << "\tsendKEEPALIVEMsg()\n\n";
	}
	bool openOK() {
		return true;
	}
	bool updateOK() {
		return true;
	}
	void sendUPDATEmsg() {
		std::cout << "\tsendUPDATEMsg()\n\n";
	}

	void setConnectRetryCounter(int retries) {
		std::cout << "\tsetConnectRetryCounter( " << retries <<" )\n\n"; // Set ConnectRetryCounter to given value
	}

	void startConnectRetryTimer() {
		std::cout << "\tstartConnectRetryTimer()\n\n"; // Start the ConnectRetryTimer
	}
	void stopConnectRetryTimer() {
		std::cout << "\tstopConnectRetryTimer()\n\n"; // Stop the ConnectRetryTimer
	}
	void setConnectRetryTimer(int retryDelay) {
		std::cout << "\tsetConnectRetryTimer( " << retryDelay <<" )\n\n"; // Set ConnectRetryTimer to given value
	}
	bool connectRetryTimerIsRunning() {
		return false; // returns whether the ConnectRetryTimer is running
	}
	void stopKeepAliveTimer() {
		std::cout << "\tstopKeepAliveTimer()\n\n";
	}
	void setKeepAliveTimer(int keepaliveTime) {
		std::cout << "\tsetKeepAliveTimer( " << keepaliveTime <<" )\n\n";
	}
	void startKeepAliveTimer() {
		std::cout << "\tstartKeepAliveTimer()\n\n";
	}
	void stopHoldTimer() {
		std::cout << "\tstopHoldTimer()\n\n";
	}
	void startHoldTimer() {
		std::cout << "\tstartHoldTimer()\n\n";
	}

	void setHoldTimer(int holdTime) {
		std::cout << "\tsetHoldTimer( " << holdTime <<" )\n\n";
	}

	void incrementCounter(int counter) {
		std::cout << "\tincrementConnectRetryCounter()\n\n";; //increments ConnectRetrycounter
	}

	bool initTCPConnection() {
		std::cout << "\tinitTCPConnection()\n\n";
		return true;// Initialize TCP Connection
	}
	void listenTCPConnections() {
		std::cout << "\tlistenTCPConnections()\n\n";
	}
	bool dropTCPConnection() {
		std::cout << "\tdropTCPConnection()\n\n";
		return false;// Drop TCP Connection
	}
	// listen TCP Connections !?*/

