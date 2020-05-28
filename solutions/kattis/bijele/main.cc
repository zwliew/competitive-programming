#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 6; ++i) {
    int t;
    cin >> t;
    if (i == 0 || i == 1) {
      cout << 1 - t << ' ';
    } else if (i == 2 || i == 3 || i == 4) {
      cout << 2 - t << ' ';
    } else {
      cout << 8 - t;
    }
  }
}