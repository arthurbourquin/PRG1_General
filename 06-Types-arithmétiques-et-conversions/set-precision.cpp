#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    cout << endl;
    double val = 928357.72649815275180;
    cout << "Sans 'fixed' :" << endl;
    for(int i = 0; i < 10; i++){
        cout  << i << " : " << setprecision(i) << val << endl;
    }
    cout << endl;
    cout << "Avec 'fixed' :" << endl;
    for(int i = 0; i < 10; i++){
        cout  << fixed << i << " : " << setprecision(i) << val << endl;
    }    
    cout << endl;
    return EXIT_SUCCESS;
}