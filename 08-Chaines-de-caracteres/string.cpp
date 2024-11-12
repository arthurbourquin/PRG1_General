/*
pour compiler, utiliser :alignof
-std=c++17
par exemple :
g++ -std=c++17 -o main main.cpp
*/

#include <iostream>
#include <string>
#include <cctype>
#include "ch08-string.h"

using namespace std;
using namespace ch08_string;

int main() {

    cout << endl;

    char a = 0;

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }

    cout << endl;

    string s1(16, '-');
    cout << s1 << endl;

    cout << endl;

    cout << "Alors déjà il faut bien utiliser -std=c++17 dansla compilation, sinon caca." << endl;
    cout << R"(\n passage à la ligne)" << endl;
    cout << R"(\r retour chariot « CR »)" << endl;
    cout << R"(\t tabulation horizontale)" << endl;
    cout << R"(\v tabulation verticale)" << endl;
    cout << R"(\a alerte sonore)" << endl;
    cout << R"(\\ barre oblique inverse « \ »)" << endl;
    cout << R"(\' caractère apostrophe « ' »)" << endl;
    cout << R"(\" caractère guillemet « " »)" << endl;
    cout << R"(\b retour arrière « backspace »)" << endl;
    cout << R"(\f saut de page « form feed »)" << endl;

    cout << endl;

    string voitures = "salut les voitures de courses";
    cout << voitures << endl;
    string paul(voitures, 6);
    cout << paul << endl;
    string albert(voitures, 6, 12);
    cout << albert << endl;
    paul.assign("les chats");
    cout << paul << endl;
    paul = paul + " sont " + paul;
    cout << paul << endl;
    paul = paul.append(" et c'est tous des connards");
    cout << paul << endl;
    cout << "C'est une phrase de lenght " << paul.length() << endl;
    cout << "C'est une phrase de size " << paul.size() << endl;
    paul.resize(24);
    cout << paul << endl;
    paul.resize(15);
    paul.resize(20, '#');
    cout << paul << endl;
    string chloe = paul.substr(10, 10);
    cout << chloe << endl;
    cout << chloe.erase(4, 6) << endl;
    cout << chloe.insert(0, "Les tortues ") << endl;
    cout << chloe.append(" les animaux les plus meilleurs que j'aime.") << endl;
    cout << "Paul et Chloé out." << endl;
    cout << endl;


    cout << "Début de l'histoire de Boris" << endl;
    string Boris;
    cout << (Boris += "Il y a un cheval qui te regarde par la fenêtre.") << endl;
    cout << Boris.erase(0, 1) << endl;
    cout << Boris.insert(0, "Je te jure qu'i") << endl;
    string toReplace = "regarde";
    int tempPos = Boris.find(toReplace);
    cout << Boris.replace(tempPos, toReplace.length(), "mate") << endl;
    Boris.pop_back();
    cout << Boris << endl;
    cout << (Boris += string("de la cuisine.")) << endl;
    cout << endl;


    return 0;
}
