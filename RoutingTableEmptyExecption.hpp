#ifndef ROUTINGTABLEEMTYEXEPTION_HPP_
#define ROUTINGTABLEEMTYEXEPTION_HPP_

#include <exception>
#include <string>

class RoutingTableEmptyException {
public:
	RoutingTableEmptyException(std::string s) :m_s(s) {};
	~RoutingTableEmptyException() {};

	std::string description() {
		return m_s;
	}
	const char* what() const throw() {
		return m_s.c_str();
	}

private:
	std::string m_s;
};

#endif /* WORKEREXCEPTION_HPP_ */
