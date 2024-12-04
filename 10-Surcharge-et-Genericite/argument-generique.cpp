#include <iostream>

using namespace std;

template <int n, typename T>
T multiplier(const T& t) {
return (T)n * t;
}
int main() {
    cout << multiplier<3, double>(2.5) << endl; // affiche 7.5
    cout << multiplier<5>(2.5) << endl; // par déduction, affiche 12.5
}