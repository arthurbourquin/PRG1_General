#include <iostream>

using namespace std;

using srcType = long long int;
using desType = double;

int main() {
    cout << "begin test" << endl;
    for(srcType s = 0; s < numeric_limits<srcType>::max(); ++s) {
        desType f = (desType) s;
        srcType ss = (srcType) f;
        if (ss != s) {
            cout << "loss at:" << s << " -- " << f << endl;
            break;
        }
    }
    cout << "end test" << endl;
}