#include <iostream>
using namespace std;

class Ouais {
public:
    int a, b;
    Ouais() : a(3), b(2) {};
};

ostream & operator << (ostream & os, Ouais ouais) {
    os << ouais.a << " " << ouais.b << endl;
    return os;
}

string operator + (const string & a, const string & b) {
    return a + " - " + b;
}

int main() {

    Ouais super;

    cout << super << endl;

    string cacahuete = "cacahuete";
    string koala = "koala";
    string snikatouide = cacahuete + koala;

    cout << snikatouide << endl;
    
    return 0;
}