// WIP

#include <iostream>
#include <vector>
using namespace std;

template<typename It, typename Compare = less<typename iterator_traits<It>::value_type>>
pair<It, It> plus_long_sequence_croissante(It first, It last, Compare comp = Compare()) {

    if(first == last) return {first, first};

    pair<It, It> max(first, first);
    It lead = first;
    It trail = first;

    for(; first != last; ++first) {
        if(comp(*lead, *next(lead))) {
            ++lead;
        } else {
            if(distance(trail, lead) > distance(max.first, max.second)) {
                max = {trail, lead};
            };
            ++lead;
            trail = lead;
            }
    }
    return max;
}

int main() {
    vector<int> v{1, 2, 3, 1, 2, 3, 4, 1, 2, 1, 9, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 2, 3, 4, 1, 2, 3, 4};
 
    cout << "Plus long sequence croissante (1): ";
    auto r1 = plus_long_sequence_croissante(v.begin(), v.end());
    for (auto it = r1.first; it != r1.second; ++it)
       cout << *it << ' ';
 
    cout << "\nPlus long sequence croissante (2): ";
    auto r2 = plus_long_sequence_croissante(v.cbegin(), v.cend(), less<int>{});
    for (auto it = r2.first; it != r2.second; ++it)
       cout << *it << ' ';
 
    cout << "\nPlus long sequence décroissante : ";
    auto r3 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
    for (auto it = r3.first; it != r3.second; ++it)
       cout << *it << ' ';
 
    cout << endl;
 }