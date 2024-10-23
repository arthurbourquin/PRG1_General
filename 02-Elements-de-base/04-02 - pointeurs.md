1) Créer une variable `var1` initialisée 1
2) Créer une variable `var2` initialisée 2
3) Créer une constante `cste` initialisée 3
4) Créer un pointeur non constant `ptr1` non initialisé
5) Créer un pointeur non constant `ptr2` pointant sur `var2`
6) Faire pointer `ptr1` sur `var1`
7) Modifier la valeur pointée par `ptr1` à 2
8) Afficher "oui" ou "non" selon si `ptr1` et `ptr2` pointent sur la même variable.</br>Ne pas utiliser de `if`
9) Afficher "oui" ou "non" selon si `ptr1` et `ptr2` pointent sur une valeur identique.</br>Ne pas utiliser de `if`
10) Afficher l'addresse où se trouve `var1`
11) Afficher le contenu de `ptr1`</br>Que peut-on dire de cette valeur ?
12) Afficher l'addresse où se trouve `ptr1`
13) Faire pointer `ptr1` sur `cste`
14) Déclarer un pointer non constant `ptr3` sur `cste`
~~~cpp
int var1 = 1;
int var2 = 2;
const int cste = 3;
int* ptr1 = nullptr;
int* ptr2 = &var2;
*ptr1 = &var1;
ptr1 = 2;
cout << boolalpha << (ptr1 == ptr2) << endl;
cout << boolalpha << (*ptr1 == *ptr2) << endl;
cout << &var1 << endl;
cout << ptr1 << endl; // correspond à l'adresse de var1
cout << *ptr1 <<  endl;
; // conflit / illégal
const int* ptr3 = &cste;
~~~



# Pointeurs

Coder en C++ les questions suivantes.

**NB** : les instructions sont dépendantes les unes des autres

1) Créer une variable `var1` initialisée 1

<details>
<summary>Réponse</summary>

`int var1 = 1;`

</details>

2) Créer une variable `var2` initialisée 2

<details>
<summary>Réponse</summary>

`int var2 = 2;`

</details>

3) Créer une constante `cste` initialisée 3

<details>
<summary>Réponse</summary>

`const int cste = 3;`

</details>

4) Créer un pointeur non constant `ptr1` non initialisé

<details>
<summary>Réponse</summary>

`int* ptr1;`

</details>

5) Créer un pointeur non constant `ptr2` pointant sur `var2`

<details>
<summary>Réponse</summary>

`int* ptr2 = &var2;`

</details>

6) Faire pointer `ptr1` sur `var1`

<details>
<summary>Réponse</summary>

`ptr1 = &var1;`

</details>

7) Modifier la valeur pointée par `ptr1` à 2

<details>
<summary>Réponse</summary>

`*ptr1 = 2;`

</details>

8) Afficher "oui" ou "non" selon si `ptr1` et `ptr2` pointent sur la même variable.</br>Ne pas utiliser de `if`

<details>
<summary>Réponse</summary>

`cout << (ptr1 == ptr2 ? "oui" : "non");`

</details>

9) Afficher "oui" ou "non" selon si `ptr1` et `ptr2` pointent sur une valeur identique.</br>Ne pas utiliser de `if`

<details>
<summary>Réponse</summary>

`cout << (*ptr1 == *ptr2 ? "oui" : "non");`

</details>

10) Afficher l'addresse où se trouve `var1`

<details>
<summary>Réponse</summary>

`cout << &var1;`

</details>

11) Afficher le contenu de `ptr1`</br>
Que peut-on dire de cette valeur ?

<details>
<summary>Réponse</summary>

`cout << ptr1;`</br>

=> ce sera la même que `&var1`

</details>

12) Afficher l'addresse où se trouve `ptr1`

<details>
<summary>Réponse</summary>

`cout << &ptr1;`

</details>

13) Faire pointer `ptr1` sur `cste`

<details>
<summary>Réponse</summary>

Pas possible, un `int*` (avec droit RW) ne peut pas pointer sur une constante 

`const int ...`

</details>

14) Déclarer un pointer non constant `ptr3` sur `cste`

<details>
<summary>Réponse</summary>

`const int* ptr3 = &cste;`

</details>

