/*************************************************************************
                           Analog  -  Description
                             -------------------
    début                : 09/01/2017
    e-mail               : $EMAIL
*************************************************************************/

#include <limits>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

#include "Analog.h"
#include "LogReader.h"

using std::string;
using std::endl;
using std::cout;

//------------------------------------------- Constantes, statiques et types privés

const std::string NODE_PREFIX = "node";
const uint MAX_DISPLAY_LINES = 10;

//------------------------------------------- Méthodes protégées et privées



void Analog::generateGraph(std::ostream &output)
{
    typedef std::map<std::string, Page>::iterator it_map_type;
    typedef std::unordered_map<Page *, unsigned int>::iterator it_umap_type;
    std::unordered_map<Page *, string> nodes;

    // First line

    output << "digraph {" << endl;


    // Node declaration

    it_map_type iterator = pages.begin();

    for (int i = 0; iterator != pages.end(); iterator++, i++)
    {
        std::string num;
        std::stringstream convert;
        convert << i;
        convert >> num;

        nodes[&(iterator->second)] = NODE_PREFIX + num;
        // Declare nodes
        output << nodes[&(iterator->second)] << " [label=\"" << iterator->first << "\"];" << endl;
    }


    // Nodes links

    for (iterator = pages.begin(); iterator != pages.end(); iterator++)
    {
        std::unordered_map<Page *, unsigned int> tmp = iterator->second.Referrers();

        for (it_umap_type iterator_bis = tmp.begin(); iterator_bis != tmp.end(); iterator_bis++)
        {
            output << nodes[iterator_bis->first] << " -> " << nodes[&(iterator->second)] << " [label=\""
                   << tmp[iterator_bis->first] << "\"];" << endl;
        }
    }

    // Last line

    output << "}" << endl;

}

void Analog::readFile(std::string fileName)
{
    std::ifstream ifs(fileName, std::ifstream::in);

    LogReader lr(ifs);

    LogEntry e;

    while (lr >> e)
    {
        pages[e.page].AddHit(&pages[e.referrer]);
    }
}


void Analog::writeFile(std::string fileName, std::ostream &output)
{

}

void Analog::displayTop()
{
    std::vector<std::pair<string, Page>> items(pages.begin(), pages.end());

    auto cmp = [](std::pair<string, Page> const &a, std::pair<string, Page> const &b) {
        return a.second.Hits() != b.second.Hits() ? a.second.Hits() > b.second.Hits() : a.first < b.first;
    };

    std::sort(items.begin(), items.end(), cmp);

    std::vector<std::pair<string, Page>>::iterator it;
    uint count = 0;

    for (it = items.begin(); it != items.end() && count < MAX_DISPLAY_LINES; it++, count++)
    {
        cout << it->first << " (" << it->second.Hits() << " hits)" << endl;
    }
}


//------------------------------------------- METHODES PUBLIC

int Analog::Run(AnalogOptions parameters)
{
    this->parameters = parameters;

    readFile(parameters.fileName);

    displayTop();
    return 0;
}

//------------------------------------------- Redefinition d'operateurs

//------------------------------------------- Constructeurs - destructeur


Analog::Analog()
{

}

Analog::~Analog()
{

}
