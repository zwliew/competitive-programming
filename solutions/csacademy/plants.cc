#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int rooms[m];
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        rooms[i] = t;
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (rooms[j] >= a && rooms[j] <= b) ++cnt;
        }
        cout << cnt << '\n';
    }
}