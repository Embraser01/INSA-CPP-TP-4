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
    std::pair<bool, int> time;
    std::string fileName;
};

//------------------------------------------- Rôle de la classe
// Rôle : La classe Analog est la classe principale du programme, qui regroupe
// les grands axes du fonctionnement du programme.
//-------------------------------------------


class Analog
{
//--------------------------------------- Méthodes publiques

public:

    int Run(AnalogOptions parameters);
	// Mode d'emploi :
	//     Lance le programme avec les options passées en ligne de commande.
	//     * parameters : les parametres de lancement de programme

    //--------------------------------------- Redéfinition d'opérateurs

    //--------------------------------------- Constructeurs - destructeur

    Analog();
	// Mode d'emploi :
	//     Construit un objet Analog vierge.

    virtual ~Analog();
	// Mode d'emploi :
	//     Détruit un objet Analog.


//--------------------------------------- Méthodes protégées ou privées

protected:
private:
    void readFile(std::string fileName);
	// Mode d'emploi :
	//     Lit un fichier de log et stocke les pages ainsi récupérées dans la
	//     map pages.
	//     * fileName : nom du fichier de log

    void writeGraph(std::string fileName);
	// Mode d'emploi :
	//     Ecrit le fichier GraphViz correspondant au graphe de pages.
	//     * fileName : nom du fichier GraphViz

    void generateGraph(std::ostream &output);
	// Mode d'emploi :
	//     Génère un graphe et l'écrit dans le flux output.
	//     * output : flux dans lequel le graph généré doit être écrit

    void displayTop();
	// Mode d'emploi :
	//     Affiche le top 10 des pages les plus visitées.

//--------------------------------------- Attributs et types protégés ou privés

protected:
private:
    std::map<std::string, Page> pages;

    AnalogOptions parameters;

};

#endif //TP4_ANALOG_H
