// tenter de comprendre cette putain de mémoire
// "5" va-t-il exister dans l'exécution de ce script ?

int a = 17;
int b = 23;

int f1(int x) {
    return x + 1;
}

void nothing() {
    f1(4);
}

int main() {

    nothing();    
    f1(b);

    return 0;

}

