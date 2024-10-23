# Pointeurs et const
Soient les déclarations suivantes :
~~~cpp
int i = 5;
const int j = 10;

int* ptr_i = &i;
const int* ptr_j = &j;

const int* ptr_i_1 = &i;
int* const ptr_i_2 = &i;
~~~

~~~cpp

ptr_i = 15;
// la valeur pointée par ptr_i est modifiable et modifiée : i vaut 15

int *ptr_j_1 = &j;
// *ptr_j_1 devrait retourner l'adresse de ptr_j_1 qui n'existe pas...
// int* ptr_j_1 = &j aurait fonctionné, cela aurait créé un pointeur ptr_j_1 qui pointe vers j

ptr_j = ptr_i;
// 

*ptr_i_1 = 25;`
*ptr_i_2 = 30;` 
ptr_i_1 = &j;` 
ptr_i_2 = &j;`
~~~
<details>
<summary>Solution</summary>
| # | Instruction | Correcte ? (oui/non) | Explication | i, j |
|---| ---------- | --------------------- | ----------- | --- |
| 1 | `*ptr_i = 15;` | oui | i est modifiable | i=15, j=10 |
| 2 | `int *ptr_j_1 = &j;` | non | on ne peux pas initialiser un pointeur int avec un rvalue de type const int | |
| 3 | `ptr_j = ptr_i;`  | oui | ptr_j est modifiable | i=5, j=10 |
| 4 | `*ptr_i_1 = 25;` | non | un pointeur vers une valeur constante | |
| 5 | `*ptr_i_2 = 30;` | oui | const pointer vers non const lvalue | i=30, j=10 |
| 6 | `ptr_i_1 = &j;` | oui | ptr_i_1 est modifiable (non cost) | i=5, j=10 |
| 7 | `ptr_i_2 = &j;` | non | ptr_i_2 est un pointeur constant et serait lié à une constante | |
</details>