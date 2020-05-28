#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    bool f = true;
    for (char c : s) {
        if (f) {
            a += c - '0';
        } else {
            b += c - '0';
        }
        f = !f;
    }
    if (labs(a - b) % 11 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}