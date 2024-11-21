// SUCCESS

#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
   for(int i = 0; i < v.size(); i++) {
      cout << v[i];
   }
   cout << endl;
}

void rotate_right(vector<int>& v) {
   if (v.size() > 1) {
      int tmp = v.back();
      for (size_t i = v.size() - 1; i > 0; --i) {
         v[i] = v[i - 1];
      }
      v[0] = tmp;
   }
}

int main() {
   vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   for(int i = 0; i < v.size(); i++) {
      print_vector(v);
      rotate_right(v);
   }

return EXIT_SUCCESS;
}





