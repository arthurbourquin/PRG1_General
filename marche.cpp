// marche

#include <iostream>
#include <span>
#include <vector>
#include <array>
#include <random>
using namespace std;

template<typename Table_A, typename Table_B>
vector<long double> ornithorynque(Table_A a, Table_B b) {
    size_t a_length = distance(begin(a), end(a));
    size_t b_length = distance(begin(b), end(b));
    size_t total_length = a_length + b_length;
    vector<long double> result;
    while(a_length > 0 or b_length > 0) {
        if(a_length > 0) {
            int r = rand() % (a_length);
            result.push_back(a[r]);
            a_length--;
        }
        if(b_length > 0) {
            int r = rand() % (b_length);
            result.push_back(b[r]);
            b_length--;
        }
    }
    return result;
}

int main() {

    srand(time(0));



    array<int, 4> a {1, 2, 3, 4};
    double t[] = {1.431, 4.362, 5.172469, 2.2981, 4.0281, 4.92187};
    auto v = ornithorynque(a, span(t));

    for(int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }

    return 0;
}