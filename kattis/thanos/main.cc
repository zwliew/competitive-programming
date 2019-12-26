#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int r, f, c = 0;
    ll p;
    cin >> p >> r >> f;
    while (p <= f) {
      ++c;
      p *= r;
    }
    cout << c << '\n';
  }
}