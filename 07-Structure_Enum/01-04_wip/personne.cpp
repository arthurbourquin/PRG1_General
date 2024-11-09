#include <iostream>
#include "personne.h"

using namespace std;

void afficher_personne(const Personne& personne){
    cout << "ouais" << personne.nom << endl;
    cout << "ouais" << personne.adresse << endl;
    cout << "ouais"; afficher_date(personne.dateDeNaissance);
    cout << std::endl;
}