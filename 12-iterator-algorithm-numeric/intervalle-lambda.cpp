#include <iostream>
#include <algorithm>
#include <vector>
#include <span>

using namespace std;

ostream& operator<< (ostream& os, vector<int> s) {
   os << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) os << ", ";
      os << s[i];
   }
   return os << "]";
}

struct InRange {
    int min, max;
    InRange(int min, int max) : min(min), max(max) {}
    bool operator()(int e) const {
        return e >= min && e <= max;
    }
};

int main() {

   int min = 3, max = 6;
   vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   cout << endl;
   cout << v << endl;
   cout << endl;
   cout << count_if(v.begin(), v.end(), [min, max](int e) {return e >= min && e <= max;}) << endl;

   cout << endl;
   cout << count_if(v.begin(), v.end(), InRange(min, max)) << endl;

   cout << endl;

}