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

    unsigned int Hits() const;
    // TODO Documentation


    const std::unordered_map<Page *, unsigned int> &Referrers();
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
    std::unordered_map<Page *, unsigned int> referrers;
    unsigned int hits;

};

#endif //TP4_PAGE_H
