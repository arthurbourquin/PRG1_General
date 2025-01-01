#include <iostream>
#include <vector>
using namespace std;

vector<int> v = {1, 2, 3, 4, 5};
vector<int> w = {11, 22, 33, 44, 55};

void print(vector<int> v) {
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    print(v);
    print(w);
    v.erase(v.begin() + 3);
    print(v);
    print(w);


    return 0;
}