//
// Created by Tristan on 16/01/2017.
//

#include "LogReader.h"

#include <string>

LogReader::LogReader(std::istream &inputStream) : m_inputStream(inputStream)
{

}

int LogReader::GetMonthIndex(const std::string & monthName)
{
	static const std::map<std::string, int> months
	{
			{ "Jan", 0 },
			{ "Feb", 1 },
			{ "Mar", 2 },
			{ "Apr", 3 },
			{ "May", 4 },
			{ "Jun", 5 },
			{ "Jul", 6 },
			{ "Aug", 7 },
			{ "Sep", 8 },
			{ "Oct", 9 },
			{ "Nov", 10 },
			{ "Dec", 11 }
	};

	const auto iter(months.find(monthName));

	return (iter != std::cend(months)) ? iter->second : -1;
}

LogReader::operator bool() const
{
	return m_inputStream;
}

LogReader& operator>>(LogReader& lr, LogEntry& e)
{
	getline(lr.m_inputStream, e.ip, ' ');

	if (input.eof())

	getline(lr.m_inputStream, e.userLogname, ' ');

	getline(lr.m_inputStream, e.authenticatedUser, ' ');

	lr.m_inputStream.ignore(1, '[');

	std::string day;
	getline(lr.m_inputStream, day, '/');
	e.timeDate.tm_mday = std::stoi(day);

	std::string month;
	getline(lr.m_inputStream, month, '/');
	e.timeDate.tm_mon = GetMonthIndex(month);

	std::string year;
	getline(lr.m_inputStream, year, ':');
	e.timeDate.tm_year = std::stoi(year);

	std::string hour;
	getline(lr.m_inputStream, hour, ':');
	e.timeDate.tm_hour = std::stoi(hour);

	std::string minute;
	getline(lr.m_inputStream, minute, ':');
	e.timeDate.tm_min = std::stoi(minute);

	std::string second;
	getline(lr.m_inputStream, second, ' ');
	e.timeDate.tm_sec = std::stoi(second);

	std::string timezone;
	getline(lr.m_inputStream, timezone, '}');

	lr.m_inputStream.ignore(2);

	getline(lr.m_inputStream, e.method, ' ');

	getline(lr.m_inputStream, e.page, ' ');

	getline(lr.m_inputStream, e.version, '"');

	lr.m_inputStream.ignore(1, ' ');

	std::string status;
	getline(lr.m_inputStream, status, ' ');
	e.status = std::stoi(status);

	std::string size;
	getline(lr.m_inputStream, size, ' ');
	e.size = std::stoi(size);

	lr.m_inputStream.ignore(1, '"');

	getline(lr.m_inputStream, e.referrer, '"');

	lr.m_inputStream.ignore(2);

	getline(lr.m_inputStream, e.userAgent, '"');

	return lr;
}
