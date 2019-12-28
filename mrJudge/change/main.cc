#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a;
  int c[4], d[4] = {5, 10, 20, 50};
  cin >> c[0] >> c[1] >> c[2] >> c[3] >> a;

  int rt = INT_MAX;
  int rc[4];
  for (int i = 0; i <= c[2]; ++i) {
    int x = a;
    if (i * 20 > x) {
      break;
    }

    int cc[4] = {0, 0, i, 0};
    int t = i;
    x -= i * 20;
    for (int ci = 3; ci >= 0; --ci) {
      if (ci == 2) continue;
      int n = min(x / d[ci], c[ci]);
      x -= n * d[ci];
      t += n;
      cc[ci] = n;
    }
    if (!x && t < rt) {
      rt = t;
      copy(cc, cc + 4, rc);
    }
  }

  if (rt == INT_MAX) {
    cout << -1;
  } else {
    cout << rc[0] << ' ' << rc[1] << ' ' << rc[2] << ' ' << rc[3] << ' ' << rt;
  }
}