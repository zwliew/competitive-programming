#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2) odd++;
        else even++;
    }
    cout << even * odd;
}