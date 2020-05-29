#include <iostream>

using namespace std;

int main() {
    int dx = 0, dy = 0;
    char c;
    while (cin >> c) {
        if (c == 'N') ++dy;
        else if (c == 'S') --dy;
        else if (c == 'E') ++dx;
        else if (c == 'W') --dx;
    }
    cout << abs(dx) + abs(dy);
}