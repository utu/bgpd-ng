#ifndef SOCKETEXCEPTION_HPP_
#define SOCKETEXCEPTION_HPP_

#include <exception>
#include <string>

class SocketException {
public:
	SocketException(std::string s) :m_s(s) {};
	~SocketException() {};

	std::string description() {
		return m_s;
	}
	const char* what() const throw() {
		return m_s.c_str();
	}

private:
	std::string m_s;
};

#endif /* SOCKETEXCEPTION_HPP_ */
