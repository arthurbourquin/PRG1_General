#include <iostream>
using namespace std;

enum class Color {Red, Green, Blue};
enum Jour {FAUX, LU, MA, ME, JE, VE, SA, DI};

void printColor(Color color) {
    switch (color) {
        case Color::Red:
            cout << "Red\n";
            break;
        case Color::Green:
            cout << "Green\n";
            break;
        case Color::Blue:
            cout << "Blue\n";
            break;
        default:
            cout << "Unknown color\n";
    }
}

string f(Jour x) {switch(x) {case LU: "fermé"; break;}}

int main() {

    Color myColor = Color::Green;
    Jour cool = SA;

    printColor(myColor);

    cout << cool << endl;

    return 0;
}
