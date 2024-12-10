# Littéraux constants

Pour chacune des lignes de code suivante, indiquez 
- si elle compile
- si oui
  - quel est le type de la variable
  - ce que la ligne affiche; 
                                                 compile   type      cout                   correction
auto v1 = 1.5;        cout << v1 << endl;        oui       double    1.50000 ou 1.49999     ~
auto v2 = 1E3;        cout << v2 << endl;        oui       double    100.000                ~
auto v4 = 12.0u;      cout << v4 << endl;        non                                        correct
auto v6 = 1.0L;       cout << v6 << endl;        non                                        x
auto v7 = .5;         cout << v7 << endl;        oui       double    0.50000                ~
auto v8 = 5.;         cout << v8 << endl;        oui       double    5.00000                ~
auto v14 = 0x0.2;     cout << v14 << endl;       non                                        correct
auto v17 = 0x1.p0;    cout << v17 << endl;                                                  x
auto v18 = 0x1.8p+0f; cout << v18 << endl;                                                  x
auto v19 = 0x1.p-2L;  cout << v19 << endl;                                                  x
auto v20 = 0x1.1p+2;  cout << v20 << endl;                                                  x
