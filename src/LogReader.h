#ifndef TP4_LOGREADER_H
#define TP4_LOGREADER_H

//------------------------------------------- Interfaces utilisées, Types, Constantes

#include <istream>
#include "LogEntry.h"

//------------------------------------------- Rôle de la classe
// Rôle : Permet de lire un log en convertissant les lignes en objet LogEntry,
// qui représente de façon structurée les informations d'une entrée.
//-------------------------------------------

class LogReader
{
//--------------------------------------- Méthodes publiques
public:
    int GetMonthIndex(const std::string &monthName);
    // Mode d'emploi :
    //     Retourne un index entre 0 et 11 correspondant au mois en forme
    //     abbréviée trouvable dans le log (e.g. 'Sep').
    //     * monthName : nom de mois abbrévié
    //
    // Contrat :
    //     monthName nom de mois abbrévié valide

    operator bool() const;
    // Mode d'emploi :
    //     Permet d'utiliser la classe comme un booleen pour vérifier si le flux
    //     sous-jacent est toujours valide, et donc si on peut lire une entrée.

    //--------------------------------------- Redéfinition d'opérateurs

    friend LogReader &operator>>(LogReader &lr, LogEntry &e);
    // Mode d'emploi :
    //     Permet d'utiliser la classe comme un flux d'entrée pour lire des
    //     entrées de log.
    //     * lr : le LogReader duquel lire
    //     * e : la LogEntry dans laquelle stocker le résultat de la lecture

    //--------------------------------------- Constructeurs - destructeur

    explicit LogReader(std::istream &inputStream);
    // Mode d'emploi :
    //     Construit un LogReader à partir d'un flux d'entrée.
    //     * inputStream : flux d'entrée d'où le log doit être lu
    //
    // Contrat :
    //     inputStream doit être un stream ouvert et en bon état.

private:
    //--------------------------------------- Attributs et types protégés ou privés

    std::istream &m_inputStream;
};

#endif //TP4_LOGREADER_H
