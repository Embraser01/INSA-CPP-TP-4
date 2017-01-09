#include "Analog.h"

//------------------------------------------- Constantes, statiques et types privés

const std::string NODE_PREFIX = "node";

//------------------------------------------- Méthodes protégées et privées



void &Analog::generateGraph(std::ostream &output)
{
    typedef std::map<std::string, Page>::iterator it_map_type;
    typedef std::unordered_map<Page *, uint>::iterator it_umap_type;
    std::unordered_map<Page *, string> nodes;


    output << "digraph {" << endl;

    it_map_type iterator = pages.begin();

    for (int i = 0; iterator != pages.end(); iterator++, i++)
    {
        nodes[&iterator->second] = NODE_PREFIX + i;
        // Declare nodes
        output << nodes[&iterator->second] << " [label=\"" << iterator->first << "\"];" << endl;
    }

    for (iterator = pages.begin(); iterator != pages.end(); iterator++, i++)
    {
        std::unordered_map<Page *, uint> tmp = iterator->second.Referrers();

        for (it_umap_type iterator_bis = tmp.begin(); iterator_bis != tmp.end(); iterator_bis++)
        {
            output << nodes[&iterator_bis->second] << " -> " << nodes[&iterator->second] << " [label=\""
                   << tmp[&iterator_bis->first] << "\"];" << endl;
        }
    }

    output << "}" << endl;

}

//------------------------------------------- METHODES PUBLIC


//------------------------------------------- Redefinition d'operateurs

//------------------------------------------- Constructeurs - destructeur

