#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void print_var_state(string names, vector<int> values) {
    for(int i = 0; i < names.size(); ++i) {
        cout << " " << names[i] << ":" << values[i] << " ";
    }
    cout << endl;
}
void print_vector(vector<string> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << "*** " << v[i] << " ***" << endl;
    }
}

int main() {

    cout<< "dites-moi tout." << endl;
    string inp_s;
    getline(cin, inp_s);
    cout << "Ok vous avez dit : " << inp_s << endl;

    vector<string> inp_v_s = {""};
    int a = 0;
    int b = 0;
    for(int i = 0; i < inp_s.size(); ++i) {
        if(inp_s[i] == ' ') {
            inp_v_s.push_back("");
            a++;
        } else {
            inp_v_s[a] += inp_s[i];
        }
    }

    print_vector(inp_v_s);

    return 0;
}