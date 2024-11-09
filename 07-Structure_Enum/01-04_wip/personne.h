#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include "date.h"

struct Personne{
    std::string nom;
    std::string adresse;
    Date dateDeNaissance;
};

void afficher_personne(const Personne& personne);

#endif