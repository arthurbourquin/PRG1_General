#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> nombres = {5, 2, 8, 1, 3};

    sort(nombres.begin(), nombres.end(), [](int a, int b) {return a < b;});

    cout << "Nombres triés par ordre décroissant : ";
    for (int n : nombres) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
