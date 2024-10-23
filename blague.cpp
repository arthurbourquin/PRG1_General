#include <iostream>
#include <iomanip>
using namespace std;

int h = 9;
int m = 40;
int t = h * 60 + m;

int main() {
    for(int i = 0; i < 100; i++){
        cout << "Il est " << setw(2) << setfill('0') << t / 60 << "h" << setw(2) << setfill('0') << t % 60;
        if(t < 12 * 60) {
            cout << " et Arthur il est toujours au Meraki." << endl;
        } else if(t < 12 * 60 + 30){
            cout << " et Arthur il est allé mager." << endl;
        } else {
            cout << " et Arthur il est de nouveau au Meraki..." << endl;
        }
        t += 5;
    }
}