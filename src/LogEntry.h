#ifndef TP4_LOGENTRY_H
#define TP4_LOGENTRY_H

//------------------------------------------- Interfaces utilisées, Types, Constantes

#include <ctime>
#include <string>

//------------------------------------------- Rôle de la structure
// Rôle : Représente une entrée de log de façon structurée et typée.
//-------------------------------------------

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
