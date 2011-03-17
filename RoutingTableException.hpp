/*
 * RoutingTableException.hpp
 *
 *  Created on: 17.3.2011
 *      Author: noora
 */

#ifndef ROUTINGTABLEEXCEPTION_HPP_
#define ROUTINGTABLEEXCEPTION_HPP_

class RoutingTableException {
public:
	RoutingTableException(std::string s) :m_s(s) {};
	~RoutingTableException() {};

	std::string description() {
		return m_s;
	}
	const char* what() const throw() {
		return m_s.c_str();
	}

private:
	std::string m_s;
};


#endif /* ROUTINGTABLEEXCEPTION_HPP_ */
