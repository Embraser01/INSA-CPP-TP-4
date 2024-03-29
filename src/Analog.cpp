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
#include <unordered_set>
#include <vector>

#include "Analog.h"
#include "LogReader.h"

using std::string;
using std::endl;
using std::cout;

//------------------------------------------- Constantes, statiques et types privés

static const std::string NODE_PREFIX = "node";
static const std::string LOCAL_PREFIX = "http://intranet-if.insa-lyon.fr";
static const unsigned int MAX_DISPLAY_LINES = 10;

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

bool hasEnding(std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length())
    {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else
    {
        return false;
    }
}

void Analog::readFile(std::string fileName)
{
    std::ifstream ifs(fileName, std::ifstream::in);

	if (!ifs.is_open())
	{
		cout << "Erreur, impossible d'obtenir un flux de lecture." << endl;
		return;
	}

    LogReader lr(ifs);

    LogEntry e;

    while (lr >> e)
    {
        if (parameters.time.first)
        {
            if (!(parameters.time.second <= e.timeDate.tm_hour && e.timeDate.tm_hour < parameters.time.second + 1))
            {
                continue;
            }
        }

        if (parameters.exclude)
        {
            static const std::unordered_set<std::string> ext
                    {
                            ".png",
                            ".jpeg",
                            ".jpg",
                            ".gif",
                            ".bmp",
                            ".tiff",
                            ".ico",
                            ".js",
                            ".css"
                    };

            bool end = false;
            for (std::string s : ext)
            {
                if (hasEnding(e.page, s))
                {
                    end = true;
                    break;
                }
            }

            if (end)
            {
                continue;
            }
        }
        size_t foundPage = e.page.find_first_of("?#;");
        size_t foundRef = e.referrer.find_first_of("?#;");
        size_t foundLocalPrefixPage = e.page.find(LOCAL_PREFIX);
        size_t foundLocalPrefixRef = e.referrer.find(LOCAL_PREFIX);

        string page = e.page;
        string referrer = e.referrer;

        if (foundPage != string::npos)
        {
            page = page.substr(0, foundPage);
        }
        if (foundRef != string::npos)
        {
            referrer = referrer.substr(0, foundRef);
        }
        if (foundLocalPrefixPage == 0)
        {
            page = page.erase(foundLocalPrefixPage, LOCAL_PREFIX.size());
        }
        if (foundLocalPrefixRef == 0)
        {
            referrer = referrer.erase(foundLocalPrefixRef, LOCAL_PREFIX.size());
        }

        pages[page].AddHit(&pages[referrer]);
    }
}


void Analog::writeGraph(std::string fileName)
{
    if (std::ifstream(fileName))
    {
        cout << "File already exists, do you want to continue ? (y/N): ";
        string entry;
        getline(std::cin, entry);

        if (tolower(entry[0]) != 'y')
        {
            return;
        }
    }

    std::ofstream ofs(fileName);

    // On vérifie que le fichier existe et est lisible & inscriptible

    if (!ofs.is_open())
    {
        cout << "Erreur, impossible d'obtenir un flux d'écriture" << endl;
        return;
    }
    // TODO Check if exists/etc…

    generateGraph(ofs);

    cout << "Dot-file " << fileName << " generated" << endl;
}

void Analog::displayTop()
{
    std::vector<std::pair<string, Page>> items(pages.begin(), pages.end());

    auto cmp = [](std::pair<string, Page> const &a, std::pair<string, Page> const &b) {
        return a.second.Hits() != b.second.Hits() ? a.second.Hits() > b.second.Hits() : a.first < b.first;
    };

    std::sort(items.begin(), items.end(), cmp);

    std::vector<std::pair<string, Page>>::iterator it;
    unsigned int count = 0;

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


    if (parameters.graph.first)
    {
        writeGraph(parameters.graph.second);
    }
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
