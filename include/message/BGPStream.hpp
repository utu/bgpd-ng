#ifndef BGPSTREAM_HPP_
#define BGPSTREAM_HPP_

#include <iostream>
#include "BGPMessage.hpp"
#include "UpdateMessage.hpp"
#include "OpenMessage.hpp"
#include "MessageException.hpp"

class ostream;
class BGPStream {
public:
	BGPStream(ostream& ostr) : ostr(ostr) {}
	const std::ostream& operator<< (MessageHeader& header);
	const std::ostream& operator<< (UpdateMessageBody& body);
	const std::ostream& operator<< (OpenMessageBody& body);
private:
	ostream& ostr;
};

#endif
