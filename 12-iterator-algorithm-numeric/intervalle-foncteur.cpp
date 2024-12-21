#include <iostream>
#include <algorithm>
#include <vector>
#include <span>

using namespace std;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, span<T> s) {
   os << "[";
   for (size_t i=0; i<s.size(); ++i) {
      if (i) os << ", ";
      os << s[i];
   }
   return os << "]";
}

//---------------------------------------------------------
template <typename T>
struct entre {
   const T& min;
   const T& max;
   bool operator() (const T& e) { return e >= min and e <= max; }
};

//---------------------------------------------------------
int main() {

   vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   cout << span(v) << endl;

   cout << count_if(v.begin(), v.end(), entre<int>{3, 6});
}