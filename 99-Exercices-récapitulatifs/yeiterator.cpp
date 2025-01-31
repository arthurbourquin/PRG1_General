#include <iostream>
#include <vector>
using namespace std;

template<typename It, typename Comparator = less<int>>
pair<It, It> plus_long_sequence_croissante(It from, It to, Comparator comp = less<int>{}) {

    It debut_plage_courante = from;
    It fin_plage_courante = from;
    It debut_plage_finale = from;
    It fin_plage_finale = from;

    for(; from != to; ++from) {
        if (next(from) != to && comp(*from, *next(from))) {
            fin_plage_courante++;
        } else {
        size_t plage_courange = distance(debut_plage_courante, next(fin_plage_courante));
        size_t plage_finale = distance(debut_plage_finale, next(fin_plage_finale));
        if(plage_courange > plage_finale) {
            debut_plage_finale = debut_plage_courante;
            fin_plage_finale = fin_plage_courante;
        }
        debut_plage_courante = next(from);
        fin_plage_courante = debut_plage_courante;
        }
    }

    return pair<It, It>(debut_plage_finale, fin_plage_finale);
}

int main() {
   vector<int> v{6, 3, 4, 5, 4, 3, 1, 2, 2, 3, 4, 3, 7};
   vector<int> vv{1, 2, 3, 1, 2, 3, 4, 5, 4, 1, 2, 3, 1, 5, 4, 3, 2, 1};

   cout << "Plus long sequence croissante (1): ";
   auto r1 = plus_long_sequence_croissante(v.begin(), v.end());
   for (auto it = r1.first; it != r1.second; ++it)
      cout << *it << ' ';

   cout << "\nPlus long sequence croissante (2): ";
   auto r2 = plus_long_sequence_croissante(v.cbegin(), v.cend(), less<int>{});
   for (auto it = r2.first; it != r2.second; ++it)
      cout << *it << ' ';

   cout << "\nPlus long sequence décroissante : ";
   auto r3 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
   for (auto it = r3.first; it != r3.second; ++it)
      cout << *it << ' ';

   cout << endl;
}