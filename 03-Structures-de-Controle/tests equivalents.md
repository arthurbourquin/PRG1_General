# Tests équivalents ? 

Les deux extraits de code suivants sont-ils équivalents ? Justifiez votre réponse.

~~~cpp 
if (prixActuel > 100) {
   nouveauPrix = prixActuel - 20;
} else {
   nouveauPrix = prixActuel - 10;
}
~~~

~~~cpp 
if (prixActuel < 100) {
   nouveauPrix = prixActuel - 10;
} else {
   nouveauPrix = prixActuel - 20;
}
~~~

`a > 100` n'est pas l'inverse de `a < 100`
il faudrait faire `a <= 100`