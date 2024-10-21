#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool lire_fichier(const std::string& nom_fichier){
    ifstream SkiaDdans;
    SkiaDdans.open(nom_fichier);
    while(SkiaDdans) {
        string lalaligne;
        getline(SkiaDdans, lalaligne);
        cout << lalaligne << '\n';
    }
    SkiaDdans.close();
    return 0;
}

bool ecrire_fichier(const std::string& nom_fichier) {
    ofstream SkonMeDdans;
    SkonMeDdans.open(nom_fichier);
    if(!SkonMeDdans) {
        cerr << "Ah ça marche pas !" << endl;
        return 1;
    }
    cout << "Ecrire 'STOP' pour arrêter ce truc." << endl;
    string LUtilisateurIlAEcritCa;
    cin >> LUtilisateurIlAEcritCa;
    while(true) {
        SkonMeDdans << LUtilisateurIlAEcritCa << '\n';
        if(LUtilisateurIlAEcritCa == "STOP") break;
    }

    return 0;
}

int main() {
    std::string nom_fichier;

    std::cout << "Entrez le nom du fichier où enregistrer le texte : ";
    std::getline(std::cin, nom_fichier);

    lire_fichier(nom_fichier);

    ecrire_fichier(nom_fichier);

    return EXIT_SUCCESS;
}