#ifndef WORKEREXCEPTION_HPP_
#define WORKEREXCEPTION_HPP_

#include <exception>
#include <string>

class WorkerException {
public:
	WorkerException(std::string s) :m_s(s) {};
	~WorkerException() {};

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
