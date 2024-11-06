#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <cstdlib>

struct Personne{
    std::string nom;
    std::string adresse;
    Date dateDeNaissance;
};

void afficher_personne(Personne personne){}

#endif