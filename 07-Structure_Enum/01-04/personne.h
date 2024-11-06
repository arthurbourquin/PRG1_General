#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <cstdlib>

struct Personne{
    string nom;
    string adresse;
    Date dateDeNaissance;
};

void afficher_personne(Personne personne){
    std::cout << "Nom          : " << personne.nom << std::endl;
    std::cout << "Adresse      : " << personne.adresse << std::endl;
    std::cout << "Anniversaire : " << personne.dateDeNaissance << std::endl;
}

#endif