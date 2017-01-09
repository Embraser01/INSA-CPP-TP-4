/*************************************************************************
                           Analog  -  Description
                             -------------------
    début                : 09/01/2017
    e-mail               : $EMAIL
*************************************************************************/

#include <limits>

#include "Analog.h"


void Analog::parse(std::istream &input)
{
    std::string pageName;
    std::string referrer;

    std::string hour;
    std::string minute;
    std::string second;
    struct tm time;

    while (true) {
        input.ignore(std::numeric_limits<std::streamsize>::max(), ':');

        if (input.eof()) break;

        getline(input, hour, ':');
        time.tm_hour = std::stoi(hour);

        getline(input, minute, ':');
        time.tm_min = std::stoi(minute);

        getline(input, second, ' ');
        time.tm_sec = std::stoi(second);

        input.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        input.ignore(std::numeric_limits<std::streamsize>::max(), ' ');

        getline(input, pageName, ' ');

        input.ignore(std::numeric_limits<std::streamsize>::max(), '"');
        input.ignore(std::numeric_limits<std::streamsize>::max(), '"');

        getline(input, referrer, '"');

        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
