/* Réécrivez les extraits de code suivants en
n'utilisant ni `if` ni `switch` mais exclusivement
des opérateurs de comparaisons et des opérateurs
logiques. */

#include <iostream>
#include <random>
using namespace std;

bool b;

int f1_p(int i) {
   if (i < 1) {
      b = true;
   } else {
      b = i > 2;
   }return b;
}
int f1_s(int i) {
   return (i < 1) || (i > 2);
}

int f2_p(int i, int j, int k) {
   if (j == 0) {
      b = true;
   } else {
      if (i / j < k) {
         b = false;
      } else {
         b = true;
      }
   }
   return b;
}
int f2_s(int i, int j, int k) {
   return (j == 0) || !(i / j < k);
}

int f3_p(int i, int j, int k) {
   if (j == 0) {
      b = false;
   } else {
      if (i / j < k) {
         b = true;
      } else {
         b = false;
      }
   }
   return b;
}
int f3_s(int i, int j, int k) {
   return (j != 0) && (i / j < k);
}


int rand2() {
   int min = -5; int max = 5;
   return rand() % (max - min + 1) + min;
}

int main() {
   cout << endl;
   for(int a = 0; a < 10; a++) {
      int i = rand2() % 10; int j = rand2() % 10; int k = rand2() % 10;
      cout << endl;
      cout << i << " " << j << " " << k << endl;
      cout << endl;
      cout << f1_p(i) << f2_p(i, j, k) << f3_p(i, j, k) << endl;
      cout << f1_s(i) << f2_s(i, j, k) << f3_s(i, j, k) << endl;
   }
   cout << endl;
   return EXIT_SUCCESS;
}

