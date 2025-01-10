#include <iostream>
using namespace std;

template<typename T>
class Ouais {
    T a, b;
public:
    T get_a() {return a;}
    T get_b() {return b;}
    Ouais(T init_a, T init_b) : a(init_a), b(init_b) {};
};

template<typename T>
ostream & operator << (ostream & os, Ouais<T> & ouais) {
    os << ouais.get_a() << " " << ouais.get_b() << endl;
    return os;
}

string operator + (const string & a, const string & b) {
    return a + " - " + b;
}

int main() {

    Ouais super(3, 5);

    cout << super << endl;

    string panda = "panda";
    string roux = "roux";
    string nicky = panda + roux;

    cout << nicky << endl;
    
    return 0;
}