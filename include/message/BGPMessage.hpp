#ifndef BGPMESSAGE_HPP_
#define BGPMESSAGE_HPP_

#include <inttypes.h>

#ifndef CHECK_BIT
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#endif

struct MessageHeader {
	__uint32_t marker[4];
	/* 2-octet unsigned integer indicates the total length of the
	 * message, including the header in octets.
	 */
	__uint16_t length;
	__uint8_t type;
};

class BGPMessage {
public:
	static const __uint8_t MESSAGE_TYPE_OPEN = 1;
	static const __uint8_t MESSAGE_TYPE_UPDATE = 2;
	static const __uint8_t MESSAGE_TYPE_NOTIFICATION = 3;
	static const __uint8_t MESSAGE_TYPE_KEEPALIVE = 4;
	static const __uint8_t MESSAGE_TYPE_ROUTEREFRESH = 5;

	static const __uint8_t MESSAGE_DIRECTION_OUTGOING = 1;
	static const __uint8_t MESSAGE_DIRECTION_INCOMING = 2;

	BGPMessage();
	BGPMessage(const char* message);
	~BGPMessage();
	const __uint8_t messageType() {return hdr->type;}
	void setMessageType(__uint8_t type) {hdr->type = type;}
	const __uint16_t messageLength() {return hdr->length;}
	void setMessageLenght(__uint16_t length) {hdr->length = length;}
	__uint8_t messageDirection() {return msg_direction;};
	virtual const char* message() {return msg;}
	const MessageHeader& messageHeader() {return *hdr;}
private:
	const __uint8_t msg_direction;
	const char* msg;
	MessageHeader* hdr;

	void initHeader();
};
#endif
