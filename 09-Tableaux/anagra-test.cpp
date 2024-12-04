#include <iostream> // 1pt include correct
#include <string>
#include <cctype>
#include <array>
using namespace std;

bool sontAnagrammes(const string& chaine1, const string& chaine2) {
    const size_t nbLettres = 26;
    array<int, nbLettres> freqChaine1 {};
    array<int, nbLettres> freqChaine2 {};
    for (char c : chaine1) {
        if (isalpha(c)) {
            freqChaine1[tolower(c) - 'a']++; //
    }
}

for (char c : chaine2) { if (isalpha(c)) {
    freqChaine2[tolower(c) - 'a']++; }
}

return freqChaine1 == freqChaine2;
    for(int i = 0; i < nbLettres; i++) {
        if (freqChaine1[i] != freqChaine2[i]) {
            return false;
         }
    }
    return true;
}

void tell(const string &a, const string &b) {
    cout << a;
    if (sontAnagrammes(a, b)) {
        cout << " est un anagramme de ";
    } else {
        cout << " n'est pas un anagramme de ";
    }
    cout << b << endl;
}

int main() {
    tell("laurent", "renault");
    tell("bob", "toto");
    tell("sugus", "sugus");
    tell("arthur", "rrthua");
    tell("fouad hanna", "hanna fouad");
    tell("salut", "talus");
    return EXIT_SUCCESS;
}