#include <iostream>
#include <vector>
#include <array>
#include <type_traits>

using namespace std;

template<typename Table_A, typename Table_B>
vector<long double> mix_tables(const Table_A& table_a, const Table_B& table_b) {
    vector<long double> result;
    for (const auto& elem : table_a) {
        result.push_back(static_cast<long double>(elem));
    }
    for (const auto& elem : table_b) {
        result.push_back(static_cast<long double>(elem));
    }
    return result;
}

template<typename T>
void print_vector(const vector<T>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<float> v {1.34, 4.17, 2.34};
    array<int, 5> a = {5, 10, 15};
    char tc[] = {'a', 'r', '9'};

    print_vector(mix_tables(v, a));
    print_vector(mix_tables(v, tc));
    print_vector(mix_tables(a, v));
    print_vector(mix_tables(a, tc));
    print_vector(mix_tables(tc, v));
    print_vector(mix_tables(tc, a));

    return 0;
}
