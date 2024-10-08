#include "lib.h"
#include <iostream>

using namespace std;

int saisir(const string& message, int min, int max){

    int saisie;
    do {
        cout << message << " [" << min << ".." << max << "] : ";
        cin >> saisie;
    } while (saisie < min || saisie > max);
        return saisie;
}

int afficher(string message, double result){
    cout << message << " : " << result << endl;
    return 7;
}