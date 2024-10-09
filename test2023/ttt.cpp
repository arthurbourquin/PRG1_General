#include <iostream>

using namespace std;

int main() {
    int cnt = 3;
    for(int i = 0; i < 2; ++i){
        for(int j = i; j < 3; ++j){
            cnt++;
        }
        cnt--;
    }
    cout << cnt << endl;
}

/*
6
*/