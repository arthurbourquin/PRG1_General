// WIP zehr

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

// truc avec rdbuf()

bool ecrire_fichier(const std::string& fichierACreer) {
    ofstream SkonMeDdans;
    SkonMeDdans.open(fichierACreer, ios::app);
    if(!SkonMeDdans) {
        cerr << "Ah ça marche pas !" << endl;
        return false;
    }
    string text;
    const string FinirOuais = "#exit#";
    cout << "Entrez le texte ouais alors.\n";
    while(getline(cin, text)) {
        if(text == FinirOuais) break;
        fichierACreer << text << endl;
    }
// ...
    return 0;
}

int main() {
    std::string fichierACopier;
    std::cout << "Entrez le nom du fichier où enregistrer le texte : ";
    std::getline(std::cin, fichierACopier);

    lire_fichier(fichierACopier);

    ecrire_fichier(fichierACreer);

    return EXIT_SUCCESS;
}