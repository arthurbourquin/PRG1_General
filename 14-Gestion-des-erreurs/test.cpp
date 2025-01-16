#include <iostream>

using namespace std;

int main() {

    int a = 7;
    int b = 42;

    try {
        try {
            if(a + b > 10)
            throw double(231.41);
        }
        catch (const double & e) {
            cout << "Traitement partiel " << e << endl;
            throw;
        }
    }
    catch (const double & e) {
        cout << "Fin du traitement " << e << endl;
    }

    return 0;
}