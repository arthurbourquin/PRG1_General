# PRG1
C++20

# Lexique des termes

**Assemblage**
- transformation du code objet en code machine exécutable
**Linkage**
- édition des liens
- permet d'associer plusieurs fichiers objets pour créer un exécutable
**Compilation**
- conversion du code source en code objet
`g++ -std=c++11 -o file file.cpp`
`g++ -std=c++17 -o file file.cpp`
`g++ -std=c++20 -Wall -Wextra -Wconversion -pedantic file.cpp -o file.exe`
`g++ main.cpp utils.cpp -o my_program` pas besoin de mentionner le .h
**Objet** instance d'une classe dans la programmation orientée objet
**Fonction** bloc de code qui effectue une tâche spécifique et ou retourne une valeur
**Méthode** fonction associée à une classe ou un objet (prog. orienté objet)
**Librairie** fonctions ou classes pré-écrites
**Bloc / bloc d'instructions** ensemble d'instructions groupées
**Passage par valeur**
- copie
**Passage par référence**
- pas de copie
- la valeur doit déjà exister et être de même type
- la valeur est modifiée
**Passage par référence constante**
- pas de copie
- garantie que l'objet ne sera pas modifié par la fonction
- clareté du code
- prise en charge des **rvalues**
**Passage par pointeur** utilisation d'adresse
**Code appelant** code qui appelle une fonction
**Code appelé** code de la fonction
**Paramètre effectif** argument réel transmis à la fonction
**Variable globale** visible partout et non détruite
**Variable locale** visible uniquement là où elle est déclarée puis détruite
**Variable statique** visible uniquement là où elle est déclarée mais non détruite
**Variable externe**
**Constante externe**
**Qualificateur** ??
**Valeur**
**Valeur par défaut** valeur utilisée par la fonction si rien n'est entré (attention à l'ordre)
**Visibilité** **Scope**
**Durée de vie**
**Récursivité**
**Cas trivial** cas de base dans une fonction récursive qui permet de terminer la récursion
**Opération** action effectuée sur des données
**Expression** ce qui renvoie une valeur (opération ou non)
**lvalue** localisation value, expression qui désigne une localisation de mémoire modifiable
**rvalue** result value, valeur temporaire qui ne correspond pas à une adresse mémoire modifiable
**Opérateur d’affectation** `=` `<<` `>>`
**Stream**
**VCS version control system**
**Versioning**

CMakeLists.txt

# Les erreurs possibles**
1. Erreurs de compilation / syntaxe
2. Erreurs d'édition de liens
  - exemple, deux fichiers qui ont une fonction de même nom
3. Erreurs d'exécution,
  - exemple out_of_range, ouais.at(10) quand ouais length < 10
  - ça fait pas ce qu'on veut (runtime error, runtime parce que "pendant l'exécution" (?))
4. Erreurs de logique
  - exemple, somme = a -b

# Incrémentation (décrémentation)
~~~cpp
int compteur = 42;
compteur++;              // compteur vaut 43, postfix
++compteur;              // compteur vaut 44, prefix
int pre = ++compteur;    // compteur vaut 45
                         // et pre vaut 45
int post = compteur++;   // compteur vaut 46
                         // mais post vaut 45
int i = 0;
j = (i++ == 0)
// i = 1
// j = 1 (true)
~~~

# Git

git add .
git commit -m "update"
git push -u origin main

git pull

git init
git clone https://site.ouais
git add ouais.cpp
git commit -m "ouais"
git status
git reset ouais.cpp
git diff
git diff ouais.cpp
git diff --staged
git checkout ouais.cpp
git rm ouais.cpp
git mv ouais.cpp
git branch
git branch branche
git checkout branche
git merge branche
git push
git fetch alias
git pull
https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests

# Opérateur trinaire (trilatéral / “vaisseau spatial”)**
<=>
~~~cpp
auto result = a <=> b;
if (result < 0){}
else if (result == 0){}
else {}
~~~

# Opérareur ternaire
~~~cpp
a = (a < b) ? 37 : 77;
a = (a < b) ? (b < c ? c : b) : a;
a < b ? (cout << "a est plus petit") : (cout << "a est pas plus petit");
~~~

# priorité des opérations
01. --> ` :: ` Scope resolution
02. --> ` a++ a-- ` Suffix/postfix increment and decrement
    --> ` type() type{} ` Functional cast
    --> ` a() ` Function call
    --> ` a[] ` Subscript
    --> ` . -> ` Member access
03. <-- ` ++a --a ` Prefix increment and decrement
    <-- ` +a -a ` Unary plus and minus
    <-- ` ! ~ ` Logical NOT and bitwise NOT
    <-- ` (type) ` C-style cast
    <-- ` *a ` Indirection (dereference)
    <-- ` &a ` Address-of
    <-- ` sizeof ` Size-of[note 1]
    <-- ` co_await ` await-expression (C++20)
    <-- ` new new[] ` Dynamic memory allocation
    <-- ` delete delete[] ` Dynamic memory deallocation
04. --> ` .* ->* ` Pointer-to-member
05. --> ` a*b a/b a%b ` Multiplication, division, and remainder
06. --> ` a+b a-b ` Addition and subtraction
07. --> ` << >> ` Bitwise left shift and right shift
08. --> ` <=> ` Three-way comparison operator (since C++20)
09. --> ` < <= > >= ` For relational operators < and ≤ and > and ≥ respectively
10. --> ` == != ` For equality operators = and ≠ respectively
11. --> ` a&b ` Bitwise AND
12. --> ` ^ ` Bitwise XOR (exclusive or)
13. --> ` | ` Bitwise OR (inclusive or)
14. --> ` && ` Logical AND
15. --> ` || ` Logical O
16. <-- ` a?b:c ` Ternary conditional[note 2]--Right-to-left
    <-- ` throw ` throw operator
    <-- ` co_yield ` yield-expression (C++20)
    <-- ` = ` Direct assignment (provided by default for C++ classes)
    <-- ` =+= -= ` Compound assignment by sum and difference
    <-- ` *= /= %= ` Compound assignment by product, quotient, and remainder
    <-- ` <<= >>= ` Compound assignment by bitwise left shift and right shift
    <-- ` &= ^= |= ` Compound assignment by bitwise AND, XOR, and OR
17. --> ` , ` Comma


# Google C++ guideline

# Fonctions
**Paramètre de la fonction**
**Paramètre effectif**
**conversion implicite** argument de mauvais type entré dans une fonction, automatiquement converti ou pas selon

# Conversion
~~~cpp
char a = 65; // A
int a = 'A'; // 65
float f = static_cast<float>(i);
std::string s = to_string(f);
int i = std::stoi(s);
float f = std::stof(s);
int i = static_cast<int>(f);
std::string s = std::to_string(i);
~~~

# quitter une fonction
`return` a la même fonction qu'un `break` : ça arrête la fonction
`return` d'une fonction void, c'est vraiment encore plus pareil
à la fin d'une fonction, la dernière accolade ajoute un return
fonction `void` et `main`, pas besoin de `return`

# Librairies
Fichier principal `.cpp`
Fichier d'entête `.h`
Fichier de... `.cpp`

# Structure de contrôle
- switch
- if else
- boucles
  - for
  - for each
  - while
  - do while

# fstream
~~~cpp
std::ofstream ouais;
ouais.open("super.txt");
if(!open) {std::cerr << "Erreur, mec..."; return 1;}
~~~
`iostream`      **_i_o_stream_** input / output stream **objects**
`istream`       **_i___stream_** input          stream **objects**
`ostream`       **___o_stream_** output         stream **objects**

`fstream`       **_____f_stream_** input /output **file** stream
`ifstream`      **_i___f_stream_** input         **file** stream
`ofstream`      **___o_f_stream_** output        **file** stream

`stringstream`  **______string_stream_** input / output stream operating on strings
`istringstream` **_is___string_stream_** input          stream operating on strings
`ostringstream` **____o_string_stream_** output         stream operating on strings


# IEEE 754
**format normalisé**
de 0
0  0000 0000     0000 0000 0000 0000 0000 000
à 1
0  0111 1111 `1` 0000 0000 0000 0000 0000 000
**format dénormalisé**
de 1
0  0111 1111 `1` 0000 0000 0000 0000 0000 000
à 3.4 e38
0  1111 1110 `1` 1111 1111 1111 1111 1111 111
**infini**
0  1111 1111 `1` 0000 0000 0000 0000 0000 000
**-infini**
1  1111 1111 `1` 0000 0000 0000 0000 0000 000
**NaN**
0  1111 1111 `1` xxxx xxxx xxxx xxxx xxxx xxx `où au moins un x est un 1`
1  1111 1111 `1` xxxx xxxx xxxx xxxx xxxx xxx `où au moins un x est un 1`


# Promotion


# Constructeur
string s = ("salut les voitures de courses", 6, 12) = "les voitures"


# Contante littérale VS string
**Constante littérale**
`"Hello"` est de type `const char*`, constante littérale et pointeur, vers le H (et pas un autre H dans la mémoire).
Ensuite "ça" lit jusqu'au char `\0` (premier char de la table ASCII)
Dans la mémoire, `"Hello"` est en fait `Hello\0`
**string**
`string s = "Hello"` string de type... `string`
string est une class avec
- constante littérale
- longueur
- constructeurs
- fonctions
- etc.
Attention aux conversions implicites

Pointeur constant : c'est le pointeur qui est constant

# Constante littérale
pas compris...