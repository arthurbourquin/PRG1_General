#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Dites-moi tout." << endl;
    string input;
    getline(cin, input);
    cout << "Ok, vous avez dit : " << endl;
    cout << input << endl;
    cout << endl;
    cout << "Maintenant, je vais vous donner l'adresse mémoire de chaque caractère :" << endl;

    // Boucle avec accès par index
    for (size_t i = 0; i < input.size(); ++i) {
        cout << input[i] << " est ici : " << static_cast<const void*>(&input[i]) << endl;
    }
    cout << "Voilà" << endl;
    cout << endl;

    return 0;
}