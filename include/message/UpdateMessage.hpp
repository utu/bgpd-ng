#ifndef UPDATEMESSAGE_HPP_
#define UPDATEMESSAGE_HPP_

#include <inttypes.h>
#include <list>
#include "message/BGPMessage.hpp"
#include "Prefix.hpp"

class PathAttribute {
public:
	__uint8_t attr;
	__uint8_t type_code;
	__uint8_t value_length_low;
	__uint8_t value_length_high;
	const bool optional() {
		return CHECK_BIT(this->attr, 0);
	}
	const bool transitive() {
		return CHECK_BIT(this->attr, 1);
	}
	const bool partial() {
		return CHECK_BIT(this->attr, 2);
	}
	const bool extended() {
		return CHECK_BIT(this->attr, 3);
	}
	const __uint16_t value_length() {
		__uint16_t ret;
		if (this->extended()) {
			ret = (value_length_high << 8) | value_length_low;
		} else {
			ret = value_length_low;
		}
		return ret;
	}
};

struct UpdateMessageBody {
	__uint16_t withdrawn_routes_length;
	Prefix* withdrawn_routes;
	__uint16_t path_attributes_length;
	PathAttribute* path_attributes;
	Prefix* reachablity;
};

class UpdateMessage: public BGPMessage {
public:
	UpdateMessage();
	__uint16_t reachabilityLength();
	void addWithdrawnRoute(const Prefix& prefix);
	void addPathAttribute(const PathAttribute& attrb);
	std::list<Prefix> withDrawnRoutes();
	std::list<PathAttribute> pathAttributes();
private:
	UpdateMessageBody body;
};

#endif
