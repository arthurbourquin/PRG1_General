~~~cpp

int a = 1;
const int b = 2;

1.
int* p = &a;
// p est un pointeur modifiable p pointe vers l'entier a. On peut modifier la valeur a via p ou a.

2.
int* const p = &a;
// p est un pointeur constant vers a, donc l'adresse stockée par p ne peut pas changer, mais on peut modifier la valeur pointée.

3.
const int* p = &a;
// p est un pointeur modifiable vers un entier constant, donc on ne peut pas modifier la valeur pointée par p, mais l'adresse à laquelle il pointe peut changer.
// remarque : on ne peut pas modifier a via p mais a reste modifiable

4.
const int* const p = &a;
// p est un pointeur constant vers un entier constant. Ni l'adresse ni la valeur pointée ne peuvent être modifiées.
// remarque : on ne peut pas modifier a via p mais a reste modifiable

5.
int* p = &b;
// Erreur : Non-conversion valide entre const int* et int*. Impossible d'affecter l'adresse d'un entier constant (b) à un pointeur non constant. Le pointeur p pourrait théoriquement permettre de modifier b, ce qui est interdit.

6.
int* const p = &b;
// Erreur : Même raison que pour la précédente : une conversion de const int* vers int* n'est pas autorisée.

7.
const int* p = &b;
// p est un pointeur vers un entier constant, donc cela respecte la constante b. On ne peut pas modifier la valeur pointée.

8.
const int* const p = &b;
// p est un pointeur constant vers un entier constant. Ni l'adresse ni la valeur pointée ne peuvent être modifiées.

~~~
