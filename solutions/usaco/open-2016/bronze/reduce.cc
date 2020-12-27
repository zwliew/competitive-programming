#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "reduce"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<array<int, 2>> pos(N), x(N), y(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i][0] >> y[i][0];
    x[i][1] = y[i][1] = i;
    pos[i] = {x[i][0], y[i][0]};
  }
  nth_element(x.begin(), x.begin() + 1, x.end());
  nth_element(y.begin(), y.begin() + 1, y.end());
  nth_element(x.begin() + 2, x.begin() + N - 2, x.end());
  nth_element(y.begin() + 2, y.begin() + N - 2, y.end());

  auto tryRemove = [&](int idx) {
    int xsi = idx == x[0][1];
    int ysi = idx == y[0][1];
    int xei = N - 1 - (idx == x[N - 1][1]);
    int yei = N - 1 - (idx == y[N - 1][1]);
    return (y[yei][0] - y[ysi][0]) * (x[xei][0] - x[xsi][0]);
  };

  int ans = INT_MAX;
  ans = min(ans, tryRemove(x[0][1]));
  ans = min(ans, tryRemove(x[N - 1][1]));
  ans = min(ans, tryRemove(y[0][1]));
  ans = min(ans, tryRemove(y[N - 1][1]));
  cout << ans;
}
