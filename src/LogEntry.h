//
// Created by Tristan on 16/01/2017.
//

#ifndef TP4_LOGENTRY_H
#define TP4_LOGENTRY_H

#include <ctime>
#include <string>

struct LogEntry
{
    std::string ip;
    std::string userLogname;
    std::string authenticatedUser;

    struct tm timeDate;

    std::string method;
    std::string page;
    std::string version;

    int status;

    int size;

    std::string referrer;

    std::string userAgent;
};


#endif //TP4_LOGENTRY_H
