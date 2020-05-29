#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b += x;
    }
    if (a > b) cout << 1;
    else if (a < b) cout << 2;
    else cout << 0;
}