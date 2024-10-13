#include <iostream>

using namespace std;

int compare_str(const string& s1,const string& s2) {
    int result = 0;
    int i = 0;
    while(i < s1.length() || i < s2.length()){
        if(s1[i] > s2[i]){ // string 1 is "greater"
            result = 1;
            break;
        } else if(s1[i] < s2[i]) { // string 2 is "greater"
            result = -1;
            break;
        } else if(i == s1.length()) { // string 1 and string 2 are equal
            result = 0;
        }
        i++;
    }
    return result;
}

int main() {
    string str_1, str_2;

    getline(cin, str_1);
    getline(cin, str_2);

    cout << compare_str(str_1, str_2);
}