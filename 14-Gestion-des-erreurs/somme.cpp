#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
using namespace std;

size_t sommeNPremiersEntiers(int n) {
   if(n < 1) throw invalid_argument("Oh non... c'est pas un entier positif...");
   size_t sum = 1;
   for(size_t i = 1; i <= n; ++i) {
      sum += i;
   }
   if(sum > numeric_limits<int>::max()) throw overflow_error("Oh non, trop grand résultat...");
   return sum;
};

void test(int n);

int main() {

   test(-1);
   test(0);
   test(1);
   test(65535);
   test(65536);

   return EXIT_SUCCESS;
}

void test(int n) {
   cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
   try {
      cout << " = " << sommeNPremiersEntiers(n) << endl;
   } catch (const exception& e) {
      cout << ": " << e.what() << endl;
   }
}