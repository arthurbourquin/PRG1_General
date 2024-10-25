#include <iostream>

using namespace std;

void f1_p(int a) {
   if (a == 1) {
      cout << "A";
   } else if (a == 4) {
      cout << "C"; 
   } else if (a == 2) {
      cout << "E";
   } else {
      cout << "BA";
   }        
}
void f1_s(int a) {
   switch(a) {
      case 1: cout << "A"; break;
      case 2: cout << "E"; break;
      case 4: cout << "C"; break;
      default: cout << "BA";
   }
}

void f2_p(int a) {
   if (a < 0 or a >= 5) {
      cout << "D";
   } else if (a < 3) {
      cout << "A";
   } else {
      cout << "B";
   }
}
void f2_s(int a) {
   switch(a) {
      case 0:
      case 1:
      case 2: cout << "A"; break;
      case 3:
      case 4: cout << "B"; break;
      default: cout << "D";
   }
}

int main() {
   int from = -1; int to = 7;
   cout << endl;
   for(int i = from; i < to; i++) {f1_p(i); cout << " ";} cout << endl;
   for(int i = from; i < to; i++) {f1_s(i); cout << " ";} cout << endl;
   cout << endl;
   for(int i = from; i < to; i++) {f2_p(i); cout << " ";} cout << endl;
   for(int i = from; i < to; i++) {f2_s(i); cout << " ";} cout << endl;
   cout << endl;
   return EXIT_SUCCESS;
}