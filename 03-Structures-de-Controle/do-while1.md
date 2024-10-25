# `do while` (1)

Que va afficher à l'exécution chacun des groupes d'instructions ci-dessous ?

~~~cpp
// 1
int i = 1;
do {
   cout << i << " ";
   ++i;
} while (i < 10); 
~~~

1 2 3 4 5 6 7 8 9

~~~cpp
// 2
int i = 0;
do {
   cout << i << " ";
   ++i;
} while (i < 0); 
~~~

0 

~~~cpp
// 3
int i = 1;
do {
   cout << ++i << " ";
} while (i < 10); 
~~~

2 3 4 5 6 7 8 9 10

~~~cpp
// 4
int i = 20;
do {
   cout << i << " ";
   i /= 2;
} while (i > 0); 
~~~

20 10 5 2 1 

~~~cpp
// 5
int i = 20;
do {
   cout << i << " ";
   i /= 2;
} while (i < 0); 
~~~

20 