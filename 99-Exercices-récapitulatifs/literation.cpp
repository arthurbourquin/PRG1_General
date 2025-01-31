#include <iostream>
#include <vector>
#include <array>
using namespace std;

template<typename It>
void f(It left, It right) {
    It aaa = left;
    It bbb = right;
    It ccc = left;
    It ddd = right;

    cout << endl;
    for(; left != right; ++left) {
        cout << *left;
        if(*left < *(left + 1)) {
            cout << "/";
        } else if(*left == *(left + 1)) {
            cout << "-";
        } else {
            cout << "\\";
        }
    }
    cout << endl;
}

int main() {

    vector<int> v{1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5};
    array<double, 5> a{1, 2, 3, 4, 5};

    f(v.begin(), v.end());
    f(a.begin(), a.end());
    
    return 0;
}