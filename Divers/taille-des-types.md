bool                                          0                             1     1

signed char                                -128                           127
unsigned char                                 0                           255     8

signed short                            -32'768                        32'767
unsigned short                                0                        65'535    16   16 mille

signed int                       -2'147'483'648                2'147'483'647
unsigned int                                  0                 4'294'967'295    32    4 milliards

signed long                      -2'147'483'648                 2'147'483'647
unsigned long                                 0                 4'294'967'295    32    4 milliards

signed long long     -9'223'372'036'854'775'808     9'223'372'036'854'775'807
unsigned long long                            0    18'446'744'073'709'551'615    64   18 trillions

float                              1.5 × 10^−45                   3.4 × 10^38
double                            5.0 × 10^−324                  1.7 × 10^308



signed short int, Accepted
signed int, Accepted
signed long int, Accepted
signed long long int, Accepted
unsigned short int, Accepted
unsigned int, Accepted
unsigned long int, Accepted
unsigned long long int, Accepted

signed short char, Not accepted
signed char, Accepted
signed long char, Not accepted
signed long long char, Not accepted
unsigned short char, Not accepted
unsigned char, Accepted
unsigned long char, Not accepted
unsigned long long char, Not accepted

signed short float, Not accepted
signed float, Accepted
signed long float, Not accepted
signed long long float, Not accepted
unsigned short float, Not accepted
unsigned float, Accepted
unsigned long float, Not accepted
unsigned long long float, Not accepted

signed short double, Not accepted
signed double, Accepted
signed long double, Not accepted
signed long long double, Not accepted
unsigned short double, Not accepted
unsigned double, Accepted
unsigned long double, Not accepted
unsigned long long double, Not accepted




Qui l'emporte :
- signé non signé
- celui qui permet la valeur représentable la plus élevée
Si un point chacun il faut regarder la doc je crois...


3 * 1000 * 1000 * 1000 = 3 milliards qui n'est pas représentable en int et int est ok pour toutes les opérations dont il reste et donc la valeur sera fausse