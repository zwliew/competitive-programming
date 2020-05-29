#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> freq(10);
    int n;
    cin >> n;
    if (!n) {
        cout << 0;
        return 0;
    }
    while (n) {
        freq[n % 10]++;
        n /= 10;
    }
    for (int i = 1; i <= 9; ++i) {
        if (freq[i] != freq[i - 1]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}