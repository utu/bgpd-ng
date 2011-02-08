#ifndef SOCKETEXCEPTION_HPP_
#define SOCKETEXCEPTION_HPP_

#include <string>

class SocketException {
public:
	SocketException(std::string s) :m_s(s) {};
	~SocketException() {};

	std::string description() {
		return m_s;
	}

private:
	std::string m_s;
};

#endif /* SOCKETEXCEPTION_HPP_ */
