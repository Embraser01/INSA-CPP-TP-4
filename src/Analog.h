#ifndef TP4_ANALOG_H
#define TP4_ANALOG_H

//------------------------------------------- Interfaces utilisées, Types, Constantes

#include <fstream>
#include <string>
#include <map>
#include "Page.h"

//------------------------------------------- Rôle de la classe
// Rôle : TODO Documentation
//-------------------------------------------


class Analog
{
//--------------------------------------- Méthodes publiques

public:

    int Run(std::pair<bool, std::string> graph, bool exclude, std::pair<bool, struct tm> time, std::string fileName);
    // TODO Documentation

    //--------------------------------------- Redéfinition d'opérateurs

    //--------------------------------------- Constructeurs - destructeur

    Analog();
    // TODO Documentation

    virtual ~Analog();
    // Destructeur


//--------------------------------------- Méthodes protégées ou privées

protected:
private:
    std::istream &readFile(std::string fileName);
    // TODO Documentation


    void writeFile(std::string fileName, std::ostream &output);
    // TODO Documentation

    void parse(std::istream &input);
    // TODO Documentation

    std::ostream &generateGraph();
    // TODO Documentation

    void displayTop();
    // TODO Documentation

//--------------------------------------- Attributs et types protégés ou privés

protected:
private:
    std::map <std::string, Page> catalog;

};

#endif //TP4_ANALOG_H