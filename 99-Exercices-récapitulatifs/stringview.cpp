#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;


void to_lower(string & s) {
    for(size_t i = 0; i < s.size(); ++i) {
        if(s[i] >= (size_t)('A') && s[i] <= (size_t)('Z')) {
            s[i] -= ((size_t)('A') - (size_t)('a'));
        }
    }
}

bool contient_doublon_consecutif(const string & s) {
    for(size_t i = 0; i < s.size() - 1; ++i) {
        if(s[i] == s[i + 1]) return true;
    }
    return false;
}

bool verifier(string_view a, string_view b) {

    cout << endl;
    
    cout << "base   a:  " << a << "   b:  " << b << endl;
    if(a.size() != b.size()) return false;
    
    string sa = (string)a;
    string sb = (string)b;
    cout << "copies sa: " << sa << "   sb: " << sb << endl;
    
    stable_sort(sa.begin(), sa.end());
    stable_sort(sb.begin(), sb.end());
    cout << "sorted sa: " << sa << "   sb: " << sb << endl;

    if(contient_doublon_consecutif(sa)) return false;
    if(contient_doublon_consecutif(sb)) return false;

    to_lower(sa);
    to_lower(sb);
    cout << "low    sa: " << sa << "   sb: " << sb << endl;

    unique(sa.begin(), sa.end());
    unique(sb.begin(), sb.end());
    cout << "unique sa: " << sa << "   sb: " << sb << endl;

    for(size_t i = 0; i < sa.size(); ++i) {
        if(sa[i] != sb[i]) return false;
    }
    
    return true;
}

void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   tester("abcdef","FEDBAC");
   tester("abcdef","xyz123");
   tester("abcA","cAba");
}

/*
"abcdef" compatible avec "FEDBAC"
"abcdef" incompatible avec "xyz123"
"abcA" incompatible avec "cAba"
*/