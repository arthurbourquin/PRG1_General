#include <iostream>

using namespace std;

void f1_p(int a){
    switch (a) {
        case 0 : cout << "A"; break;
        case 1 : cout << "Z"; break;
        case 2 : cout << "a"; break; 
        default : cout << "b"; break;
    }
}
void f1_s(int a){
    if(a == 0) {cout << "A";} else
    if(a == 1) {cout << "Z";} else
    if(a == 2) {cout << "a";} else
               {cout << "b";}
}

void f2_p(int a){
    switch (a) {
    case 0 : cout << "0"; 
    default : cout << "D"; break;
    }
}
void f2_s(int a){
    if(a == 0) {
    cout << "0";
    }
    cout << "D";
}

void f3_p(int a){
    switch (a) {
    case 0 : 
    case 1 : 
    case 2 : 
    case 3 : 
    case 4 : 
    case 5 : cout << "A"; break;
    case 6 : cout << "3"; 
    case 7 : cout << "4"; break; 
    default : cout << "D"; 
    }
}
void f3_s(int a){
    if(a <= 5 && a >= 0) {
        cout << "A";
    } else if(a == 7 || a == 6) {
        if(a == 6) {
            cout << "3";
        }
    cout << "4";
    } else {
        cout << "D";
    }
}

int main() {
    cout << endl;
    int from = -6; int to = 15;
    for(int i = from; i < to; i++) {f1_p(i); cout << " ";} cout << endl;
    for(int i = from; i < to; i++) {f1_s(i); cout << " ";} cout << endl; cout << endl;
    for(int i = from; i < to; i++) {f2_p(i); cout << " ";} cout << endl;
    for(int i = from; i < to; i++) {f2_s(i); cout << " ";} cout << endl; cout << endl;
    for(int i = from; i < to; i++) {f3_p(i); cout << " ";} cout << endl;
    for(int i = from; i < to; i++) {f3_s(i); cout << " ";} cout << endl;
    cout << endl;
    return EXIT_SUCCESS;
}