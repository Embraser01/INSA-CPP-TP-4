#include "Page.h"

using namespace std::cout;

//------------------------------------------- Constantes, statiques et types privés

//------------------------------------------- Méthodes protégées et privées

//------------------------------------------- METHODES PUBLIC

uint Page::Hits()
{
    return hits;
}

const std::unordered_map<Page *, uint> &Page::Referrers()
{
    return referrers;
}

void Page::AddHit(Page *referrer)
{
    // Init to 0
    referrers[referrer]++;
}

//------------------------------------------- Redefinition d'operateurs

//------------------------------------------- Constructeurs - destructeur

Page::Page()
{
    hits = 0;

#ifdef MAP
    cout << "Constructeur de <Page>" << endl;
#endif
}

void Page::~Page()
{

#ifdef MAP
    cout << "Destructeur de <Page>" << endl;
#endif
}