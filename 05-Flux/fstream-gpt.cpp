#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file("fstream-gpt-file.txt", ios::in | ios::out | ios::trunc); // Ouvrir en lecture/écriture et effacer le contenu existant
    if (!file.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
        return 1; // Sortie avec erreur
    }

    // Écriture dans le fichier
    file << "Première ligne." << endl;
    file << "Deuxième ligne." << endl;

    // Remettre le pointeur au début du fichier avant de lire
    file.seekg(0, ios::beg);

    // Lecture du contenu du fichier
    cout << "Contenu du fichier :" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Ajout d'une nouvelle ligne à la fin du fichier
    file.clear(); // Effacer les états d'erreur (EOF)
    file.seekp(0, ios::end); // Placer le pointeur d'écriture à la fin du fichier
    file << "Troisième ligne ajoutée." << endl;

    // Vérification en relisant tout le contenu
    file.clear(); // Effacer les états d'erreur (EOF)
    file.seekg(0, ios::beg); // Replacer le pointeur de lecture au début
    cout << "\nContenu final du fichier :" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Fermeture du fichier
    file.close();

    return 0;
}
