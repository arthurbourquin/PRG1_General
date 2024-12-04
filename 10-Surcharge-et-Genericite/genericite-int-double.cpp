#include <iostream>
#include <vector>

using namespace std;

template <typename ouais>   


void inserer_trie(std::vector<ouais>& v, ouais val) {
    v.push_back(ouais());

    size_t i = v.size() - 1;
    while(i > 0 and v[i-1] > val) {
        v[i] = v[i-1];
        --i;
    }
    
    v[i] = val;
}


int main() {
   cout << "vector<int> : " << endl;
    vector<int> vi{4, 7};
    for(int i : { 3, 6, 8, 1, 2, 5 }) {
        inserer_trie(vi, i);
        for(auto e : vi)
            cout << e << " ";
        cout << endl;
    }

    cout << "\nvector<double> : " << endl;
    vector<double> vd{4.5, 7.5};
    for(double d : { 3.2, 6.1, 8., 1., 2.3, 5.8 }) {
        inserer_trie(vd, d);
        for(auto e : vd)
            cout << e << " ";
        cout << endl;
    }
}