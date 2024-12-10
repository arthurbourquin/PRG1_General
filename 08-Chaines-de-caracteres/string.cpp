/*
pour compiler, utiliser :alignof
-std=c++17
par exemple :
g++ -std=c++17 -o main main.cpp
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    string s_1("Hello World");
    string s_2 = "Hello World";
    string s_3 {'H', 'e', 'l', 'l', 'o'};
    string s_4(3, 'w');
    cout << s_1 << " " << s_2 << " " << s_3 << " " << s_4 << endl;

    cout << "Hello World" << endl;
    cout << string("Hello") + " World" << endl;
    cout << string(5, 's') << endl;
    cout << string(s_1, 6, 5) << endl;
    cout << string("-----takethis---------", 5, 8) << endl;
    cout << string(s_1.rbegin(), s_1.rend()) << endl;
    
    cout << string("Hello").append(" World") << endl;
    cout << string("Hello").append("In the World of our", 3, 4) << endl;
    cout << string("7777").append('7', 3) << endl;

    cout << string("déplier").insert(4, "endre ou se ") << endl;

    cout << string("123---456").erase(3, 3) << endl;
    string s("123---456"); s.erase(s.begin() + 3, s.begin() + 6); cout << s << endl;

    return 0;
}
