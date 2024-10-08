// SUCCESS

#include <iostream>

using namespace std;

int facto(int n); // déclaration du prototype de la fonction

int main() {

    cout << "Facoriel de : ";
    int n;
    cin >> n;
    cout << facto(n) << endl;

}

int facto(int n) {
    if(n <= 1)
        return 1;

    return n * facto(n -1);
}
