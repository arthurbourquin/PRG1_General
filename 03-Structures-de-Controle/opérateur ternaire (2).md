
# A corriger 

~~~cpp 
a = a >= 1 ? 42 : a * a; 
if(a >= 1) {a = 42;} else {a *= a;}

b = a == 2 ? 32 : ( a < 5 ? 12 : 23 );
if(a == 2) {b = 32;} else if(a < 5) {b = 12;} else {b = 23;}

c = a < 0 ? ( b < 0 ? a : -a ) : ( b < 5 ? a + b : a - b );
if(a < 5) {
   if(b < 0) {
      c = a
   } else {
      c = -a;
   }
} else {
   if(b < 5) {
      c = a + b;
   } else {
      c = a - b;
   }
}

~~~