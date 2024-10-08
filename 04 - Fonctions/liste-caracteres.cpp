// SUCCESS

#include <iostream>

using namespace std;

char first;
char last;

int main() {
    cout << "First character: ";
    cin >> first;
    cout << "Last character: ";
    cin >> last;

    for(int i = 0; i <= last - first; i++) {
        char c = first + i;
        cout << c;
    }
    cout << endl;

}