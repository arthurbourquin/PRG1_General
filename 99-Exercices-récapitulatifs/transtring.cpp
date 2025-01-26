#include <iostream>
#include <string>

using namespace std;

size_t transformer(string & s, const string & from, const string & to) {
    unsigned short lowToCap = (unsigned short)('A') - (unsigned short)('a'); // = 32
    string from2 = "";
    string to2 = "";
    for(size_t i = 0; i < from.size(); ++i) {
        // ajout du caractère de base dans from2
        from2.push_back(from[i]);
        // ajout du caractère de base dans to2
        to2.push_back(to[i]);
        // si le caractère est une lettre MINUSCUE, ajouter la majusule correspondante...
        if(from[i] >= (size_t)('a') && from[i] <= (size_t)('z')) {
            // ... dans from2
            from2.push_back(from[i] + lowToCap);
            // ... dans to2
            to2.push_back(to[i] + lowToCap);
        }
        // si le caractère est une lettre MAJUSCULE, ajouter la minuscule correspondante...
        if(from[i] >= (size_t)('A') && from[i] <= (size_t)('Z')) {
            // ... dans from2
            from2.push_back(from[i] - lowToCap);
            // ... dans to2
            to2.push_back(to[i] - lowToCap);
        }
    }
    cout << endl;
    cout << "from:  " << from << endl;
    cout << "from2: " << from2 << endl;
    cout << "to:    " << to << endl;
    cout << "to2:   " << to2 << endl;
    cout << endl;
    size_t modified = 0;
    for(size_t i = 0; i < s.size(); ++i) {
        for(size_t j = 0; j < from2.size(); ++j) {
            if(s[i] == from2[j]) {
                s[i] = to2[j];
                modified++;
                break;
            }
        }
    }
    return modified;
}


int main() {
   string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
   cout << transformer(s,"abcdefgh.!,:","fghabcde!,:.") << endl;
   cout << s << endl;
   cout << transformer(s,"fghabcde!,:.","abcdefgh.!,:") << endl;
   cout << s << endl;
}
