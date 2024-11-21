#include <iostream>
#include <array>
using namespace std;
using Vec3d = array<double,3>;

string to_string(Vec3d input) {
   return ("(" + to_string(input[0]) + "," + to_string(input[1]) + "," + to_string(input[2]) + ")");
}

Vec3d produit(Vec3d input, double fac) {
   return {input[0] * fac, input[1] * fac, input[2] * fac};
}

double produit_scalaire(Vec3d a, Vec3d b) {
   double result = 0;
   for(double i = 0; i < a.size() - 1; i++) {
      result += (a[i] * b[i]);
   }
   return result;   
}

Vec3d produit_vectoriel(Vec3d a, Vec3d b) {
   return {
      a[1] * b[2] - a[2] * b[1],
      a[2] * b[0] - a[0] * b[2],
      a[0] * b[1] - a[1] * b[0],
   };
}

int main() {
   Vec3d a = {1, 2, 3};
   Vec3d b = {2, 4, 3};
   cout << "a = " << to_string(a) << endl
        << "b = " << to_string(b) << endl;

   Vec3d c = produit(a, 2.);
   cout << "c = a*2 = " << to_string(c) << endl;

   cout << "a.b = " << produit_scalaire(a, b)
        << ", a.c = " << produit_scalaire(a, c)
        << ", b.c = " << produit_scalaire(b, c) << endl;

   Vec3d d = produit_vectoriel(a, b);
   cout << "d = a^b = " << to_string(d) << endl;
   cout << "a.d = " << produit_scalaire(a, d)
        << ", b.d = " << produit_scalaire(b, d) << endl;

   Vec3d e = produit_vectoriel(a, a);
   cout << "e = a^a = " << to_string(e) << endl;
}