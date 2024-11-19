// WIP

#include <iostream>

using namespace std;

struct Coord {
    int x;
    int y;
};

Coord position = {2, 2};

void update_position(Coord move) {
    position.x += move.x;
    position.y += move.y;
}

void render_frame() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << (i == position.x && j == position.y ? "*" : ",");
        }
        cout << endl;
    }
    cout << endl;
}

Coord user_input(char input) {
    switch(input) {
        case 'w' : return {0, 1}; break;
        case 's' : return {0, -1}; break;
        case 'a' : return {1, 0}; break;
        case 'd' : return {-1, 0}; break;
        default : return {0, 0}; break;
    }
}

int main() {
    render_frame();
    string c_move;
    while(true) {
        cin >> c_move;
        if(c_move == "exit") {break;}
        update_position(user_input(c_move[0]));
        render_frame();
    }

return EXIT_SUCCESS;
}
