#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string letters;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        char smallest = s[0];
        for (char c : s) {
            smallest = min(c, smallest);
        }
        letters += smallest;
    }
    sort(letters.begin(), letters.end());
    cout << letters;
}