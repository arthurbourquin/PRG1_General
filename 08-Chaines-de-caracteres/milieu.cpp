// SUCCESS

#include <iostream>
#include <string_view>
using namespace std;

string_view retourne_le_milieu(string_view s) {
    int longueur = s.length();
    if(longueur != 0) {
        if(longueur % 2 == 0) {
            return s.substr(longueur / 2 - 1, 2);
        } else {
            return s.substr(longueur / 2, 1);
        }
    } else {
        return "caca";
    }
}

int main() {
    cout << "Entrez du texte et je vous montre le milieu : " << endl;
    string s;
    cin >> s;
    cout << retourne_le_milieu(s) << endl;

    return EXIT_SUCCESS;
}