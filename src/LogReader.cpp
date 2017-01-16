//
// Created by Tristan on 16/01/2017.
//

#include "LogReader.h"

#include <sstream>
#include <map>
#include <iterator>

LogReader::LogReader(std::istream &inputStream) : m_inputStream(inputStream)
{

}

int LogReader::GetMonthIndex(const std::string &monthName)
{
    static const std::map<std::string, int> months
            {
                    {"Jan", 0},
                    {"Feb", 1},
                    {"Mar", 2},
                    {"Apr", 3},
                    {"May", 4},
                    {"Jun", 5},
                    {"Jul", 6},
                    {"Aug", 7},
                    {"Sep", 8},
                    {"Oct", 9},
                    {"Nov", 10},
                    {"Dec", 11}
            };

    const auto iter(months.find(monthName));

    return (iter != std::end(months)) ? iter->second : -1;
}

LogReader::operator bool() const
{
    return (bool) m_inputStream;
}

LogReader &operator>>(LogReader &lr, LogEntry &e)
{
    std::stringstream convert;

    getline(lr.m_inputStream, e.ip, ' ');

    if (lr.m_inputStream.eof()) return lr;

    getline(lr.m_inputStream, e.userLogname, ' ');

    getline(lr.m_inputStream, e.authenticatedUser, ' ');

    lr.m_inputStream.ignore(1, '[');

    std::string day;
    getline(lr.m_inputStream, day, '/');
    convert << day;
    convert >> e.timeDate.tm_mday;
    convert.clear();

	convert.str("");
convert.clear();;

    std::string month;
    getline(lr.m_inputStream, month, '/');
    e.timeDate.tm_mon = lr.GetMonthIndex(month);

    std::string year;
    getline(lr.m_inputStream, year, ':');
    convert << year;
    convert >> e.timeDate.tm_year;
    convert.clear();

	convert.str("");
convert.clear();

    std::string hour;
    getline(lr.m_inputStream, hour, ':');
    convert << hour;
    convert >> e.timeDate.tm_hour;
    convert.clear();

	convert.str("");
convert.clear();

    std::string minute;
    getline(lr.m_inputStream, minute, ':');
    convert << minute;
    convert >> e.timeDate.tm_min;
    convert.clear();

	convert.str("");
convert.clear();

    std::string second;
    getline(lr.m_inputStream, second, ' ');
    convert << second;
    convert >> e.timeDate.tm_sec;
    convert.clear();

	convert.str("");
convert.clear();

    std::string timezone;
    getline(lr.m_inputStream, timezone, ']');

    lr.m_inputStream.ignore(2);

    getline(lr.m_inputStream, e.method, ' ');

    getline(lr.m_inputStream, e.page, ' ');

    getline(lr.m_inputStream, e.version, '"');

    lr.m_inputStream.ignore(1, ' ');

    std::string status;
    getline(lr.m_inputStream, status, ' ');
    convert << status;
    convert >> e.status;
    convert.clear();

	convert.str("");
convert.clear();

    std::string size;
    getline(lr.m_inputStream, size, ' ');
    convert << size;
    convert >> e.size;
    convert.clear();

    lr.m_inputStream.ignore(1, '"');

    getline(lr.m_inputStream, e.referrer, '"');

    lr.m_inputStream.ignore(2);

    getline(lr.m_inputStream, e.userAgent, '"');

    lr.m_inputStream.ignore(2, '\n');

    return lr;
}
