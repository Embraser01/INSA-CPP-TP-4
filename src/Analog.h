#ifndef TP4_ANALOG_H
#define TP4_ANALOG_H

//------------------------------------------- Interfaces utilisées, Types, Constantes

#include <fstream>
#include <string>
#include <map>
#include "Page.h"


struct AnalogOptions
{
    std::pair<bool, std::string> graph;
    bool exclude;
    std::pair<bool, uint> time;
    std::string fileName;
};

//------------------------------------------- Rôle de la classe
// Rôle : TODO Documentation
//-------------------------------------------


class Analog
{
//--------------------------------------- Méthodes publiques

public:

    int Run(AnalogOptions parameters);
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
    void readFile(std::string fileName, std::istream &input);
    // TODO Documentation

    void writeFile(std::string fileName, std::ostream &output);
    // TODO Documentation

    void parse(std::istream &input);
    // TODO Documentation

    void generateGraph(std::ostream &output);
    // TODO Documentation

    void displayTop();
    // TODO Documentation

//--------------------------------------- Attributs et types protégés ou privés

protected:
private:
    std::map<std::string, Page> pages;

    AnalogOptions parameters;

};

#endif //TP4_ANALOG_H
