#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int d1 = abs(r1 - i) + abs(c1 - j);
            int d2 = abs(r2 - i) + abs(c2 - j);
            if (d1 == d2) ++ans;
        }
    }
    cout << ans;
}