// SUCCESS
// plutôt while true pour le cin

#include <iostream>
#include <string>
using namespace std;

bool est_un_palindrome(string_view s) {
    bool est_un_palindrome = true;
    for(int i = 0; i < s.length() / 2; i++) {
        if(s[i] != s[s.length() - 1 - i]) {
            est_un_palindrome = false;
            break;
        }
    }
    return est_un_palindrome;
}

int main() {
    cout << endl;
    cout << "Entrer le mot ou la phrase et je vous dis si c'est un palindrome : " << endl;
    string s;
    getline(cin, s);

    cout << (est_un_palindrome(s) ? "YES ! C'est un palindrome" : "NON... C'est pas un palindrome") << endl;
    cout << endl;

return EXIT_SUCCESS;
}