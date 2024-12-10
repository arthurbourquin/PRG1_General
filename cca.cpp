#include <iostream>
using namespace std;


struct Est_multiple_de {
    int n;
    bool operator()(int a) const {return a % n == 0;}
};
auto est_pair = Est_multiple_de{2};
auto est_rond = Est_multiple_de{10};

int main() {
    
    cout << "Entrez un nombre entier bordel." << endl;
    int k; cin >> k;
    cout << k << " ";
    est_pair(k) ? est_rond(k) ? (cout << "est bien.") : (cout << "est bof.") : (cout << "est nul.");
    cout << endl;

    return 0;
}