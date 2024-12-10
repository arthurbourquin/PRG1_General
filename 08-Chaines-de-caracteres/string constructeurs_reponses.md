~~~cpp
string s(std::string, int length)
string s(char a, int length)

string s1 = "ABC"; string s2(s1, 1); // BC
string s1 = "ABC"; string s2(s1, 2, 3); // C
string s1 = "ABC"; string s2(s1, 3, 2); //
string s1 = "ABC"; string s2(s1, 4, 1); // Erreur à l'exécution
string s("ABC", 3); // ABC
string s("ABC", 4); // ABC\0
string s("ABC", 5); // Comportement indéfini
string s(3, 'A'); //AAA

~~~~