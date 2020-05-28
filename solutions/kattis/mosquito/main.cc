#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, p, l, e, r, s, n;
  while (cin >> m >> p >> l >> e >> r >> s >> n) {
    int cm = m, cp = p, cl = l;
    while (n--) {
      int tmp = m;
      m = cp / s;
      cp = cl / r;
      cl = tmp * e;
    }
    cout << m << '\n';
  }
}