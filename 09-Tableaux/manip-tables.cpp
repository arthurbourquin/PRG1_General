#include <iostream>
#include <vector>
#include <span>
#include <string>
#include <algorithm> // Pour std::fill
using namespace std;

void p(const vector<string>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    cout << endl;
    vector<string> v = {"Je", "suis", "un", "cheval"};
    p(v);
    v.push_back("blanc");
    p(v);
    v.insert(v.begin() + 3, "bon");
    p(v);
    v.erase(v.begin() + 1);
    v.insert(v.begin() + 1, "vois");
    p(v);
    cout << v.front() << " " << v.back() << " " << v.size() << endl;
    fill(v.begin(), v.end(), "***");
    p(v);
    v.at(0) = "Il";
    v.at(1) = "est";
    v.at(2) = "beau";
    p(v);
    v.resize(3);
    p(v);
    v.resize(10, "oui");
    p(v);
    v.clear();
    p(v);
    v = {"Elle", "est", "une", "licorne", "extraordinaire"};
    p(v);
    v[4].replace(5, 3, "pluridiscpl");
    p(v);   
    v.pop_back();
    p(v);
    cout << "Capacity: " << v.capacity() << endl;
    v.reserve(20);
    cout << "Capacity after reserve: " << v.capacity() << endl;
    for(int i = 0; i < v.size(); ++i) {
        cout <<
        v[i].front() << " " <<
        v[i].substr(v[i].size() / 2 - 1, 3) << " " <<
        v[i].back() << endl;        
    }
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}