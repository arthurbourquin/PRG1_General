# vérifier deux string_view

Pour que la fonction de l'exercice [99-01](99-01%20transformer%20une%20string.md) 
puisse être utilisée pour encoder / décoder du texte sans perte d'information, 
il est nécessaire que les 2 chaines passées en paramètres 2 et 3 
- contiennent les mêmes caractères, en ne tenant pas compte de la casse
- ne contiennent pas de doublons 

écrire une fonction vérifier qui retourne vrai si ces critères sont 
respectés, et faux sinon. Il est recommandé d'utiliser `<algoritm>`. 

Le code suivant

~~~cpp
void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   tester("abcdef","FEDBAC");
   tester("abcdef","xyz123");
   tester("abcA","cAba");
}
~~~

affiche le résultat suivant 

~~~text
"abcdef" compatible avec "FEDBAC"
"abcdef" incompatible avec "xyz123"
"abcA" incompatible avec "cAba"
~~~

<details>
<summary>Solution</summary>

La solution la plus efficace utiliser `std::sort` et `std::unique` pour 
créer des versions comparables des 2 chaines, sans doublons. 

Il est possible d'écrire des versions moins efficaces en vérifiant 
explicitement les deux conditions avec des doubles boucles. 

~~~cpp
#include <iostream>     // cout, endl via ostream
#include <string>       // string
#include <string_view>  // string_view
#include <cctype>       // toupper
#include <algorithm>    // transform, sort, unique

using namespace std;

string ensemble_trie(string_view s) {
   auto a = string(s);
   transform(a.cbegin(), a.cend(),a.begin(), ::toupper);
   sort(a.begin(),a.end());
   a.erase(unique(a.begin(), a.end()),a.end());
   return a;
}

bool verifier(string_view a, string_view b) {
   string ea = ensemble_trie(a);
   string eb = ensemble_trie(b);
   return a.size() == ea.size()
          and b.size() == eb.size()
          and ea == eb;
}

void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   tester("abcdef","FEDBAC");
   tester("abcdef","xyz123");
   tester("abcA","cAba");
}
~~~

gpt
~~~cpp
#include <iostream>     // Pour l'utilisation de cout et endl
#include <string>       // Pour la manipulation des objets string
#include <string_view>  // Pour une gestion plus efficace des chaînes de caractères en lecture seule
#include <cctype>       // Pour la fonction toupper (conversion en majuscules)
#include <algorithm>    // Pour transform, sort, et unique

using namespace std;

/**
 * @brief Transforme une chaîne en majuscules, trie ses caractères par ordre croissant,
 *        et supprime les doublons.
 * 
 * @param s La chaîne de caractères en entrée
 * @return Une chaîne contenant les caractères triés et sans répétitions
 */
string ensemble_trie(string_view s) {
   // Convertit string_view en string modifiable
   auto a = string(s);
   
   // Transforme tous les caractères en majuscules
   transform(a.cbegin(), a.cend(), a.begin(), ::toupper);
   
   // Trie la chaîne par ordre croissant
   sort(a.begin(), a.end());
   
   // Supprime les caractères dupliqués adjacents
   a.erase(unique(a.begin(), a.end()), a.end());
   
   return a; // Retourne la chaîne transformée
}

/**
 * @brief Vérifie si deux chaînes contiennent exactement les mêmes caractères,
 *        sans répétition, indépendamment de la casse.
 * 
 * @param a Première chaîne
 * @param b Deuxième chaîne
 * @return true si les deux chaînes sont compatibles, false sinon
 */
bool verifier(string_view a, string_view b) {
   // Transformation des chaînes en ensembles triés sans doublons
   string ea = ensemble_trie(a);
   string eb = ensemble_trie(b);

   // Vérifie que chaque chaîne initiale ne comportait pas de caractères en double
   // et que les ensembles obtenus sont identiques
   return a.size() == ea.size()
          and b.size() == eb.size()
          and ea == eb;
}

/**
 * @brief Affiche si deux chaînes sont compatibles selon le critère défini.
 * 
 * @param a Première chaîne
 * @param b Deuxième chaîne
 */
void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   // Teste différentes combinaisons de chaînes
   tester("abcdef", "FEDBAC");  // Compatible (mêmes lettres, ordre et casse ignorés)
   tester("abcdef", "xyz123");  // Incompatible (lettres différentes)
   tester("abcA", "cAba");      // Incompatible (car 'A' apparaît en double)

   return 0;
}
~~~
</details>