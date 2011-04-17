#ifndef HEADER_HPP_
#define HEADER_HPP_

#ifndef CHECK_BIT
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

struct MessageHeader {
	__uint16_t length;
	__uint8_t type;
};

#endif
