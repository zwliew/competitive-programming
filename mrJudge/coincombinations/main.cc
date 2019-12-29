#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, v;
  cin >> n >> v;

  vector<int> c(n + 1, 0);
  for (int ni = 1; ni <= n; ++ni) {
    cin >> c[ni];
  }

  vector<int> w(v + 1, 0);
  w[v] = 1;

  for (int ni = 1; ni <= n; ++ni) {
    for (int vi = 1; vi <= v; ++vi) {
      w[ni][vi] = w[ni - 1][vi];
      if (c[ni] <= vi) {
        w[ni][vi] += w[ni][vi - c[ni]];
        w[ni][vi] %= 13371337;
      }
    }
  }
  cout << w[n][v];
}