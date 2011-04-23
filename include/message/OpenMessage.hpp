#ifndef OPENMESSAGE_HPP_
#define OPENMESSAGE_HPP_

#include <inttypes.h>
#include "message/BGPMessage.hpp"
#include "Prefix.hpp"

struct OpenMessageOptionalParameters {
	__uint8_t type;
	__uint8_t length; // value length in octets
	__uint8_t* value;
};

struct OpenMessageBody {
	__uint8_t version;
	__uint16_t as_number;
	__uint16_t hold_time; // proposed hold time in seconds
	__uint32_t bgp_identifier; // BGP speaker ip
	__uint8_t parameters_length; // zero if no optional parameters
	OpenMessageOptionalParameters* parameters;
};

class OpenMessage: public BGPMessage {
	OpenMessage();
private:
	MessageHeader header;
	OpenMessageBody body;
};
#endif
