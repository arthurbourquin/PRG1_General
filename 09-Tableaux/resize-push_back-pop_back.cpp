// SUCCESS

#include <iostream>
#include <vector>
using namespace std;

void my_push_back(vector<int>& v, int a) {
   v.resize(v.size() + 1, a);
}

void my_pop_back(vector<int>& v) {
   v.resize(v.size() - 1);
}

void my_resize(vector<int>& v, int a, int b = 0) {
   while(v.size() > a) {
      v.pop_back();
   }
   while(v.size() < a) {
      v.push_back(b);
   }
}

void print_vector(vector<int> v) {
   for(int i = 0; i < v.size(); i++) {
      cout << v[i];
   }
   cout << endl;
}

int main() {
   vector<int> v{1, 2, 3, 4, 5, 6};
   print_vector(v);
   my_push_back(v, 7);
   print_vector(v);
   my_pop_back(v);
   print_vector(v);
   my_pop_back(v);
   print_vector(v);
   my_resize(v,3);
   print_vector(v);
   my_resize(v,5,1);
   print_vector(v);
   my_resize(v,8);
   print_vector(v);

return EXIT_SUCCESS;
}