#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string ouais = "uezeuuezeuezzeuezeu";

    cout << "Avant : " << ouais << endl;
    sort(ouais.begin(), ouais.end());
    auto it = unique(ouais.begin(), ouais.end());
    ouais.erase(it, ouais.end());
    cout << "Après : " << ouais << endl;

    return 0;
}
