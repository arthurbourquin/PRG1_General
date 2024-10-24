#include <iostream>
#include <cmath>

using namespace std;

int main() {
   cout << "Soit ax^2 + bx + c = 0\nEntrez a : ";
   double a;
   cin >> a;
   cout << "Entrez b : ";
   double b;
   cin >> b;
   cout << "Entrez c : ";
   double c;
   cin >> c;
   double discriminant = b * b - 4 * a * c;
   double x1; double x2;
   if(discriminant >= 0) {
      x1 = (- b + sqrt(discriminant)) / (2 * a);
      x2 = (- b - sqrt(discriminant)) / (2 * a);
   }
   int d; discriminant > 0 ? d = 1 : (discriminant == 0 ? d = 0 : d = -1);
   switch(d){
      case -1: cout << "Pas de solution réelle." << endl; break;
      case 0: cout << "Une seule solution : x = " << x1 << endl; break;
      case 1: cout << "x1 = " << x1 << "\n" << "x2 = " << x2 << endl; break;
   }
   return EXIT_SUCCESS;
}