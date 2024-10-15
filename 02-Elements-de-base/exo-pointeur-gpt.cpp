#include <iostream>
using namespace std;

int main() {
    int taille;

    // Demander à l'utilisateur la taille du tableau
    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    // Allouer dynamiquement la mémoire pour le tableau
    int* tableau = new int[taille];

    // Remplir le tableau
    for (int i = 0; i < taille; i++) {
        cout << "Entrez l'élément " << i + 1 << " : ";
        cin >> tableau[i];
    }

    // Afficher le contenu du tableau
    cout << "Contenu du tableau : ";
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }
    cout << endl;

    // Libérer la mémoire allouée dynamiquement
    delete[] tableau;

    cout << "Mémoire libérée." << endl;

    return 0;
}
