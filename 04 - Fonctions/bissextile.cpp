// SUCESS

#include <iostream>

using namespace std;

bool leap(int year) {

    if((year % 400 == 0) or ((year % 100 == 0) and (year != 0))) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int t;
    cout << "Test year: " << endl;
    cin >> t;
    cout << leap(t) << endl;

}