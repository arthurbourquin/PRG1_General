// WIP

#include <iostream>
#include <span>
#include <vector>
using namespace std;

void afficher(vector<int> v) {
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void tri_a_bulle(vector<int> & v) {
    size_t current_pair = 0;
    size_t current_size = v.size() - 1;
    for(size_t i = 0; i < v.size() - 1; ++i) {
        for(size_t j = 0; j < v.size() - 1; ++j) {
            cout << v[j];
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {

    vector<int> v{7, 9, 4, 5, 2, 8, 1, 3, 6};
    span<int> a = v;
    afficher(v);
    tri_a_bulle(v);

    return 0;
}