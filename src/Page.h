#ifndef TP4_PAGE_H
#define TP4_PAGE_H

//------------------------------------------- Interfaces utilisées, Types, Constantes

#include <string>
#include <unordered_map>

//------------------------------------------- Rôle de la classe
// Rôle : TODO Documentation
//-------------------------------------------

class Page
{
//--------------------------------------- Méthodes publiques

public:

    uint Hits();
    // TODO Documentation


    const std::unordered_map<Page *, uint> &Referrers();
    // TODO Documentation


    void AddHit(Page *referrer);
    // TODO Documentation

    //--------------------------------------- Redéfinition d'opérateurs

    //--------------------------------------- Constructeurs - destructeur

    Page();
    // TODO Documentation

    virtual ~Page();
    // Destructeur


//--------------------------------------- Méthodes protégées ou privées

protected:
private:

//--------------------------------------- Attributs et types protégés ou privés

protected:
private:
    std::unordered_map<Page *, uint> referrers;
    uint hits;

};

#endif //TP4_PAGE_H
