#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool lire_fichier(const std::string& fichierACopier){
    ifstream SkiaDdans;
    SkiaDdans.open(fichierACopier);
    if(!SkiaDdans) {
        return false;
    }
    while(SkiaDdans) {
        string lalaligne;
        getline(SkiaDdans, lalaligne);
        cout << lalaligne << "\n";
    }
    SkiaDdans.close();
    return 0;
}

bool ecrire_fichier(const std::string& fichierACreer) {
    ofstream SkonMeDdans;
    SkonMeDdans.open(fichierACreer, ios::app);
    if(!SkonMeDdans) {
        cerr << "Ah ça marche pas !" << endl;
        return false;
    }
    string OuaisLeTexte;
    const string FinirOuais = "#exit#";
    cout << "Allez, entrez le texte et entrez '" << FinirOuais << "' pour terminer la saisie. \n";
    while(getline(cin, OuaisLeTexte)) {
        if(OuaisLeTexte == FinirOuais) break;
        SkonMeDdans << OuaisLeTexte << endl;
    }

    SkonMeDdans.close();

    cout << "Ok, super, pas de problèmes et tout, normalement le fichier a été update bien." << endl;

    return true;
}

int main() {
    std::string fichierACopier;
    std::cout << "Entrez le nom du fichier où enregistrer le texte : ";
    std::getline(std::cin, fichierACopier);

    lire_fichier(fichierACopier);

    ecrire_fichier(fichierACopier);

    return EXIT_SUCCESS;
}