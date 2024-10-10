// SUCCESS

#include <iostream>

using namespace std;

bool t = true;

bool est_primaire(int x){
    int i = 2;
    while(i <= x / 2){
        if(x % i == 0){
            t = false;
            break;
        }
        i++;
    }
    return t;
}

int main() {
    cout << "Entrer les nombre entier : ";
    int n;
    cin >> n;
    cout << est_primaire(n) << endl;
    return 0;
}