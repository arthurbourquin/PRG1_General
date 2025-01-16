#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string nom_de_fichier;
    cout << "Entrez le nom du fichier : " << endl;
    getline(cin, nom_de_fichier);

    ofstream fichier_de_sortie(nom_de_fichier, ios::app);

    string ligne_inseree;
    cout << "Ajouter du texte au fichier : " <<endl;
    cout << "(Entrez \'XXX\' pour terminer.)" << endl;
    while(true) {
        getline(cin, ligne_inseree);
        if(ligne_inseree == "XXX") break;
        fichier_de_sortie << ligne_inseree << "\n";
    }

    fichier_de_sortie.close();

    return 0;
}