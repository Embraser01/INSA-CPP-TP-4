//
// Created by Tristan on 16/01/2017.
//

#ifndef TP4_LOGREADER_H
#define TP4_LOGREADER_H

#include <iostream>
#include "LogEntry.h"

class LogReader {
public:
	explicit LogReader(std::istream &inputStream);

	int GetMonthIndex(const std::string & monthName);
	operator bool() const;

	friend LogReader& operator>>(LogReader& lr, LogEntry& e);

private:
	std::istream &m_inputStream;
};

#endif //TP4_LOGREADER_H
