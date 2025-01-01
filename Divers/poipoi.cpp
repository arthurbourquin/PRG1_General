#include <iostream>

using namespace std;

int f(int a) {
    return ++a;
}

string f(string s) {
    s.append(" ajout passage par copie");
    return s;
}

string f_ref(string & s) {
    s.append(" ajout passage par référence");
    return s;
}

string f_ptr(string * s) {
    (*s).append(" ajout passage par pointeur");
    return *s;
}

int main() {

    string la_string = "la string";
    string * ptr_la_string = &la_string;

    cout << endl;

    cout << "  " << la_string << endl;

    cout << "1 " << f(la_string) << endl;

    cout << "  " << la_string << endl;

    cout << "2 " << f_ref(la_string) << endl;

    cout << "  " << la_string << endl;

    cout << "3 " << f_ptr(ptr_la_string) << endl;

    cout << "  " << la_string << endl;

    cout << "4 " << f_ptr(&la_string) << endl;

    cout << "  " << la_string << endl;

    cout << endl;
    
    return EXIT_SUCCESS;
}