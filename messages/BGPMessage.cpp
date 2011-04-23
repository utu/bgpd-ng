#include "message/BGPMessage.hpp"

BGPMessage::BGPMessage() :
	msg_direction(BGPMessage::MESSAGE_DIRECTION_OUTGOING), hdr(
			new MessageHeader) {
	initHeader();
}

BGPMessage::BGPMessage(const char* message) :
	msg_direction(BGPMessage::MESSAGE_DIRECTION_INCOMING), msg(message), hdr(
			new MessageHeader) {
	initHeader();

}

BGPMessage::~BGPMessage() {
	delete (hdr);
	delete (msg);
}

void BGPMessage::initHeader() {
	hdr->marker[0] = 4294967295;
	hdr->marker[1] = 4294967295;
	hdr->marker[2] = 4294967295;
	hdr->marker[3] = 4294967295;
}
