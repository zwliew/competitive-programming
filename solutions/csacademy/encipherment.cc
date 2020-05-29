#include <iostream>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    for (char c : s) {
        int ord = c - 'a';
        cout << p[ord];
    }
}