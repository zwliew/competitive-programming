#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> left(101), right(101);
    int n;
    cin >>n;
    for (int i = 0; i < n; ++i) {
        int sz;
        char type;
        cin >> sz >> type;
        if (type == 'R') {
            right[sz]++;
        } else if (type == 'L') {
            left[sz]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
        ans += min(left[i], right[i]);
    }
    cout << ans;
}