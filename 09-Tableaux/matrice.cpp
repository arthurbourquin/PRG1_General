// SUCC... ...my penis

#include <iostream>
#include <array>
using namespace std;

using Vec3 = array<int, 3>;
using Matrice3x3 = array<Vec3, 3>;

Vec3 produit(Matrice3x3 m, Vec3 v) {
   Vec3 w{};
   for(int i = 0; i < m.size(); i++) {
      for(int j = 0; j < m.size(); j++) {
         w[i] += m[i][j] * v[j];
      }
   }
   return w;
}

string to_string(Vec3 v) {
   string result = "";
   for(int i = 0; i < v.size(); i++) {
      result += to_string(v[i]);
   }
   result += "\n";
   return result;
}

string to_string(Matrice3x3 m) {
   string result = "";
   for(int i = 0; i < m.size(); i++) {
      result += to_string(m[i]);
   }
   return result;
}

int main() {

   Matrice3x3 m = {1, 1, 0, 0, 2, 0, 0, 0, 1};
   Vec3 v = {1, 2, 3};
   Vec3 w = produit(m,v);

   cout << to_string(m) << " *\n"
        << to_string(v) << " =\n"
        << to_string(w) << endl;

return EXIT_SUCCESS;
}