#ifndef MESSAGEEXCEPTION_HPP_
#define MESSAGEEXCEPTION_HPP_

#include <exception>
#include <string>

class MessageException {
public:
	MessageException(std::string s): msg(s) {}
	~MessageException() {}
private:
	std::string msg;
};

#endif
