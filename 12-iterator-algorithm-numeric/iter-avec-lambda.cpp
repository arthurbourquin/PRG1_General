#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {3, 4, 5};
    
    // all_of, any_of, none_of
    cout << "all_of: " << all_of(v.begin(), v.end(), [](int x){ return x > 0; }) << "\n";
    cout << "any_of: " << any_of(v.begin(), v.end(), [](int x){ return x > 4; }) << "\n";
    cout << "none_of: " << none_of(v.begin(), v.end(), [](int x){ return x < 0; }) << "\n";
    
    // for_each
    cout << "for_each: ";
    for_each(v.begin(), v.end(), [](int x){ cout << x * 2 << " "; });
    cout << "\n";

    // count, count_if
    cout << "count: " << count(v.begin(), v.end(), 3) << "\n";
    cout << "count_if: " << count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << "\n";

    // equal, mismatch
    cout << "equal: " << equal(v2.begin(), v2.end(), v.begin() + 2) << "\n";
    auto mismatch_result = mismatch(v.begin(), v.end(), v2.begin());
    cout << "mismatch: " << *mismatch_result.first << ", " << *mismatch_result.second << "\n";

    // lexicographical_compare
    cout << "lexicographical_compare: " << lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) << "\n";

    // find, find_if, find_if_not
    cout << "find: " << *find(v.begin(), v.end(), 3) << "\n";
    cout << "find_if: " << *find_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << "\n";
    cout << "find_if_not: " << *find_if_not(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << "\n";

    // find_first_of
    vector<int> subset = {4, 6};
    cout << "find_first_of: " << *find_first_of(v.begin(), v.end(), subset.begin(), subset.end()) << "\n";

    // search, search_n, find_end
    cout << "search: " << *search(v.begin(), v.end(), v2.begin(), v2.end()) << "\n";
    cout << "search_n: " << *search_n(v.begin(), v.end(), 2, 4) << "\n";
    auto find_end_result = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    cout << "find_end: " << *find_end_result << "\n";

    // adjacent_find
    vector<int> v3 = {1, 2, 2, 3};
    cout << "adjacent_find: " << *adjacent_find(v3.begin(), v3.end()) << "\n";


    return 0;
}
