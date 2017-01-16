/*************************************************************************
                           Analog  -  Description
                             -------------------
    début                : 09/01/2017
    e-mail               : $EMAIL
*************************************************************************/

#include <limits>
#include <string>
#include <iostream>

#include "Analog.h"

using std::string;
using std::endl;
using std::cout;

//------------------------------------------- Constantes, statiques et types privés

const std::string NODE_PREFIX = "node";

//------------------------------------------- Méthodes protégées et privées



void Analog::generateGraph(std::ostream &output)
{
    typedef std::map<std::string, Page>::iterator it_map_type;
    typedef std::unordered_map<Page *, uint>::iterator it_umap_type;
    std::unordered_map<Page *, string> nodes;

    // First line

    output << "digraph {" << endl;


    // Node declaration

    it_map_type iterator = pages.begin();

    for (int i = 0; iterator != pages.end(); iterator++, i++)
    {
        nodes[&(iterator->second)] = NODE_PREFIX + std::to_string(i);
        // Declare nodes
        output << nodes[&(iterator->second)] << " [label=\"" << iterator->first << "\"];" << endl;
    }


    // Nodes links

    for (iterator = pages.begin(); iterator != pages.end(); iterator++)
    {
        std::unordered_map<Page *, uint> tmp = iterator->second.Referrers();

        for (it_umap_type iterator_bis = tmp.begin(); iterator_bis != tmp.end(); iterator_bis++)
        {
            output << nodes[iterator_bis->first] << " -> " << nodes[&(iterator->second)] << " [label=\""
                   << tmp[iterator_bis->first] << "\"];" << endl;
        }
    }

    // Last line

    output << "}" << endl;

}

//------------------------------------------- METHODES PUBLIC


//------------------------------------------- Redefinition d'operateurs

//------------------------------------------- Constructeurs - destructeur



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

int Analog::Run(std::pair<bool, std::string> graph, bool exclude, std::pair<bool, uint> time, std::string fileName)
{
    return 0;
}

Analog::Analog()
{

}

Analog::~Analog()
{

}

void Analog::readFile(std::string fileName, std::istream &input)
{

}

void Analog::writeFile(std::string fileName, std::ostream &output)
{

}

void Analog::displayTop()
{

}
