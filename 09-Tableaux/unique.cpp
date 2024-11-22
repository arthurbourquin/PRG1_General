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

vector<int> rendre_unique(vector<int> v) { // supprimer les répétitions
   for()
}

int main() {
   for (vector<int> v: {vector<int>{},
                        {2},
                        {1, 2, 2, 2, 3, 1, 2, 4},
                        {2, 3, 3, 2, 2, 1},
                        {2, 2, 2},
                        {5, 4, 4, 3, 2, 2, 2, 3}}) {
      cout << to_string(v) << " -> ";
      rendre_unique(v);
      cout << to_string(v) << endl;
   }

return EXIT_SUCCESS;
}