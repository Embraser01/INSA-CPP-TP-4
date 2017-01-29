#ifndef TP4_PAGE_H
#define TP4_PAGE_H

//------------------------------------------- Interfaces utilisées, Types, Constantes

#include <string>
#include <unordered_map>

//------------------------------------------- Rôle de la classe
// Rôle : Représente une page, plus particulièrement le nombre de fois qu'elle a
// été visitée et depuis quelle page.
//-------------------------------------------

class Page
{
//--------------------------------------- Méthodes publiques

public:

    unsigned int Hits() const;
	// Mode d'emploi :
	//     Retourne le nombre total de hits de cette page.


    const std::unordered_map<Page *, unsigned int> &Referrers();
	// Mode d'emploi :
	//     Retourne la map contenant tous les referrers de cette page ainsi que
	//     leur nombre de hits associé.


    void AddHit(Page *referrer);
	// Mode d'emploi :
	//     Ajoute un hit provenant d'un referrer.
	//     * referrer : la page d'où provient le hit
	//
	// Contrat :
	//     referrer pointeur valide sur Page

    //--------------------------------------- Redéfinition d'opérateurs

    //--------------------------------------- Constructeurs - destructeur

    Page();
	// Mode d'emploi :
	//     Construit une nouvelle page sans hits


    virtual ~Page();
	// Mode d'emploi :
	//     Détruit l'objet Page


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
