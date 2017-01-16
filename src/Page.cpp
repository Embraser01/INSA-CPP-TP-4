#include <iostream>
#include "Page.h"

using std::cout;

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

Page::~Page()
{

#ifdef MAP
    cout << "Destructeur de <Page>" << endl;
#endif
}