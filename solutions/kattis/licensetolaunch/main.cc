#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, x, mi = 1e9, mx = 1e9;
  cin >> n;
  for (int ni = 0; ni < n; ++ni) {
    cin >> x;
    if (x < mx) {
      mx = x;
      mi = ni;
    }
  }
  cout << mi;
}