#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

void removeFromVector(vector<int>& vec, size_t pos) {
    if(vec.empty()) throw invalid_argument("Oh non, vecteur vide...");
    if(pos < 0 || pos >= vec.size()) throw out_of_range("Oh non, il existe pas, lui ou eux ou elle...");
};

int main() {
    vector<int> monVecteur = {1, 2, 3, 4, 5};

    try {
        removeFromVector(monVecteur, 6); // Supprime l'élément à la position 2

        // Affichage du vecteur après suppression
        for (int val : monVecteur) {
            cout << val << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
    }

    return 0;
}