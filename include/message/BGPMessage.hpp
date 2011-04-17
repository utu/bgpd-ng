#ifndef BGPMESSAGE_HPP_
#define BGPMESSAGE_HPP_

#include <inttypes.h>

class BGPMessage {
	BGPMessage();
	void readMessage(const unsigned char *message);
	const __uint8_t messageType();
private:
	static const __uint8_t MESSAGE_TYPE_OPEN = 1;
	static const __uint8_t MESSAGE_TYPE_UPDATE = 2;
	static const __uint8_t MESSAGE_TYPE_NOTIFICATION = 3;
	static const __uint8_t MESSAGE_TYPE_KEEPALIVE = 4;
	static const __uint8_t MESSAGE_TYPE_ROUTEREFRESH = 5;
};
#endif
