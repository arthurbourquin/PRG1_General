# switch -> if ... else

Soit le programme suivant

~~~cpp
#include <iostream>
using namespace std;

int main() {
   int n; cin >> n;
   
   switch (n) {
      case 0:  cout << "A";
      case 1:
      case 2:  cout << "B";
               break;
      case 3:
      case 4:
      case 5:  cout << "C";
      default: cout << "D";
   }
}
~~~

Que va-t-il afficher lorsque l'utilisateur entre comme valeur
`0` puis `1` puis `2` puis `4` puis `6` puis `-1`

`AB`puis `B` puis `B` puis `CD` puis `D` puis `D`