# PRG1
Fouad Hanna
Notes Arthur Bourquin


Le cours PRG1 est en C++20


#include <iostream>
#include <cstdlib>
using namespace std;

int main() { // un programme va toujours commencer par appeler la fonction main
}


**Compilation**
**Linkage** / édition des liens (regrouper tous les liens, pas pareil que compilation)
**Assemblage** ??

`.o` (est un objet)
`g++` ouais.o -o ouais.exe

**compilation basique**
`g++ 01_HelloWorld.cpp -o 01-HelloWorld.exe` VS `g++ -o 01_HelloWorld.cpp 01-HelloWorld.exe` > différence ?
**compilation plus sévère**
`g++ -std=c++20 -Wall -Wextra -Wconversion (...) ouais.cpp -o ouais.exe`

CLion
CMakeLists.txt

**Erreurs**
1. Erreurs de compilation / syntaxe
2. Erreurs d'édition de liens, exemple, deux fichiers qui ont une fonction de même nom
3. Erreurs d'exécution, exemple out_of_range, ouais.at(10) quand ouais length < 10
	int *p;
	p = nullprt;
	*p = 42
Erreur d'exécution, ça fait pas ce qu'on veut (runtime error, runtime parce que "pendant l'exécution" (?))
4. Erreurs de logique


endl : flucher le buffer


`main` est un `int` car il retourne une valeur `(EXIT_SUCCESS = 0)`
à vérifier / comprendre, lié à `cstdlib`


Pour debuger on met des points pour qu'il s'arrête et on peut voir "l'état du système"


Variable
`const int a = 6;` // const car ne varie pas
`int a = 3;`
`int a = 0;`
`char a = 'A';`
`string a = " Coder:";`
`bool a = true;`
`auto a = 1;` int
`auto a = 1.5;` double
`auto a = 'c'` char
`auto a = true;` bool


**Objet**
**Fonction**
**Méthode**
**Librairie**
**Bloc / bloc d'instructions**
**Object**


**Opération**
`Double a = 5 / 2`
output:
`2`
Car 5 et 2 sont automatiquement interprétées en integer puis placés dans un double


**Expression**
Ce qui renvoie une valeur (opération ou non)


**lvalue** et **rvalue**
Localisation value, Result value


**Opérateur d’affectation**
`=`
`<<`
`>>`
“Trick”
`cout << x << y`
`cout << x` devient `cout` puis
`cout << y` devient `cout` ou `y`?


**Pointeur**

**VCS version control system**
**Git**
**Versioning**

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


**Incrémentation (décrémentation)**
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

Opérateur trilatéral / ternaire / “vaisseau spatial” / faire A- B
<=>

# priorité des opérations
n *= n + 1
égal
n = n * (n + 1)

# Google C++ guideline

# Fonctions
paramètre de la fonction
paramètre effectif
comprendre le truc "pas de restriction d'appel si ... conversion implicite si nécessaire"
## Passage par valeur
## Passage par référence (pas de copie)
- variable / constante
- type
## Passage par référence constante (pas de copie)

# Conversion
/!\ Des fois possible, des fois pas /!\ (mais pas compris quand quoi...)
char a = 65;
cout << a;
A
int a = 'A';
cout << a;
65

# quitter une fonction
return a la même fonction qu'un break : ça arrête la fonction
return d'une fonction void, c'est vraiment encore plus pareil
à la fin d'une fonction, la dernière accolade ajoute un return
fonction void et main, pas besoin de return
