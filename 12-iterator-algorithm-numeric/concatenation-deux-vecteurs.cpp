//

#include <iostream>
#include <vector>
#include <array>

using namespace std;

template <typename It>
void display(It begin, It end) {
    for(It pos = begin; pos != end; ++pos) {
        cout << *pos << " ";
    }
    cout << endl;
}

template <typename T, typename Iterator1, typename Iterator2>
vector<T> concat_tab(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2) {
    vector<T> v;
    v.reserve(distance(first1, last1) + distance(first2, last2));

    while(first1 != last1) {
        v.push_back(*first1);
        first1++;
    }

    while(first2 != last2) {
        v.push_back(*first2);
        first2++;
    }

    return v;
}

int main() {
    vector<int> v1 {3, 5, 7};
    array<int, 5> arr = {101, 102, 103, 104, 105};

    auto v = concat_tab<int>(v1.begin(), v1.end(), arr.begin(), arr.end());

    display(begin(v), end(v));

return EXIT_SUCCESS;
}