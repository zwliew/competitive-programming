#include <iostream>

using namespace std;

int main() {
    int best = 0;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > best) {
            ++ans;
            best = x;
        }
    }
    cout << ans;
}