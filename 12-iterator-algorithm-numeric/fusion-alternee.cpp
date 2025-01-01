#include <iostream>
#include <array>
#include <vector>
#include <span>
using namespace std;

template<typename T>
void print_table(vector<T> v) {
   for (auto elem : v) {
      cout << elem << " ";
   }
   cout << endl;
}

template<typename T, size_t n>
void print_table(span<T, n> t[]) {
   for (size_t i : v) {
      cout << i << " ";
   }
   cout << endl;
}

template<typename T>
void print_table(array<T, 4> a) {
   for (auto elem : v) {
      cout << elem << " ";
   }
   cout << endl;
}

int main() {

   double t[] {1.23, 2523.52, 3, 423};
   vector<int> v {7, 8, 9, 10, 11, 12, 13, 14, 15};
   array<char, 4> a {'A', '*', 's', '-'};

   print_table(t);
   print_table(v);
   print_table(a);

    return EXIT_SUCCESS;
}
