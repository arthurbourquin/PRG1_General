// WIP

#include <iostream>
#include <vector>
using namespace std;

string to_string(vector<int> v) {
   string result = "";
   for(int i = 0; i < v.size(); i++) {
      result += to_string(v[i]);
   }
   return result;
}

vector<int> supprimer_valeur(vector<int> v, int a){
   int read = 0;
   int write = 0;
   while(read < v.size()) {
      if(v[read] == a) {
         read++;
      } else {         
         v[write] = v[read];
         read++;
         write++;
      }
   }
   return v;
}

int main() {
   for (vector<int> v: {vector<int>{},
                        {2},
                        {1, 2, 2, 2, 3, 1, 2, 4},
                        {2, 3, 4, 3, 2, 1},
                        {2, 2, 2},
                        {5, 4, 3, 2, 1, 2}}) {
      cout << to_string(v) << " -> ";
      supprimer_valeur(v,2);
      cout << to_string(v) << endl;
   }
return EXIT_SUCCESS;
}