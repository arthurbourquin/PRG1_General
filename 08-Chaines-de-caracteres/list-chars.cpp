// WIP

#include <iostream>
using namespace std;

int main() {
    cout << "Entrez une phrase pour obtenir la liste (c'est débile...) : " << endl;
    string a;
    getline(cin, a);
    for(int i = 0; i < a.length(); i++) {
        cout << i << ". " << a[i] << "   ";
    }
    cout << endl;
    return EXIT_SUCCESS;  
}