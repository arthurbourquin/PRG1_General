#include <iostream>

using namespace std;

int lire_entier(string msg) {
    cout << msg;
    int i = 0;
    while(true){
        cin >> i;
        if(i > 0) {break;}
        cout << "La valeur n'est pas valide" << endl;
    }
    return i;
}

int syracuse(int n) {
    int nb_iteration = 0;
    do{
        if(n % 2 == 0){
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n;
        if(n != 1){cout << "-";}
        nb_iteration++;
    } while(n != 1);
    return nb_iteration;
}

int main() {
    const string msg = "Veuillez saisir une valeur : ";
    int i = lire_entier(msg);
    cout << "La suite de Syracuse pour n = " << i << " : ";
    int nb_iteration = syracuse(i);
    cout << "\nLe nombre d'iterations = " << nb_iteration;
    cout << endl; // added for output readability
    return 0;
}