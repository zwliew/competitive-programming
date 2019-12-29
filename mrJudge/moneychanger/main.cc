#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, v;
  cin >> n >> v;

  vector<int> c(n);
  for (int ni = 0; ni < n; ++ni) {
    cin >> c[ni];
  }

  vector<int> mc(v + 1);
  mc[0] = 0;
  for (int vi = 1; vi <= v; ++vi) {
    auto cit = upper_bound(c.begin(), c.end(), vi);
    if (cit == c.begin()) {
      mc[vi] = -1;
      continue;
    }
    int cmin = INT_MAX;
    for (cit -= 1; cit >= c.begin(); --cit) {
      if (mc[vi - *cit] == -1) continue;
      cmin = min(mc[vi - *cit] + 1, cmin);
    }
    if (cmin == INT_MAX) {
      cmin = -1;
    }
    mc[vi] = cmin;
  }
  cout << mc[v];
}