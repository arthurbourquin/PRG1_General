int x = 8, int y = 5
x++ + ++y
>8+6=12
z = 12
--z + y--
>11+6=17

int a = -3
+a
>?

int b = 4
-b
>?

bool p = true
!p
>false

bool q = false
p && q
>false

int a = 15, int b = 20
a < b
>true
a == b
>false

int x = 6, int y = 11
x & y
>true
x | y
>?

int a = 5
a += 3
>8

int b = 10
b -= 4
>6

int a = 10, int b = 15, bool condition = true
condition ? a : b
>10

!condition ? b : a + b.
>15

int x = 8, int y = 5, int z = 12
++x + --y + z
>9+4+12=25
x + y + z--
>9+4+12=25

int a = -3, int b = 4
a * -b
>12
-a + b++
>?

bool r = true
!(p && q) || r
>true
(p || q) && r
>p?q?

int a = 15, int b = 20
a <=> b
>1
a >= b
>false

int x = 6
x << 1
>?

int y = 11
y >> 2
>?

int c = 15
c *= 2
>30

int a = 5;
a /= 2
>2

int a = 10, int b = 15
(a > b) ? a : (b > a) ? b : 0
>15

condition ? (a + b) : (a - b)
>?

int a = 1, int b = 2
result = (a++, b += 2, a + b)
abo
1
 2
2
 4
  6
ab
24
>6
result = b = 2, b + c
>c?