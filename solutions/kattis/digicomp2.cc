#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

vector<vector<array<int, 2>>> adj;
vector<bool> initial;
vector<array<int64_t, 3>> dp;

void compute(int u) {
  if (dp[u][2] != -1)
    return;
  dp[u][2] = 0;
  for (auto& [v, d] : adj[u]) {
    compute(v);
    dp[u][2] += dp[v][d];
  }
  dp[u][0] = dp[u][1] = dp[u][2] / 2;
  dp[u][initial[u]] += dp[u][2] % 2;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int64_t N;
  int M;
  cin >> N >> M;
  adj.resize(M + 1);
  initial.resize(M + 1);
  dp.assign(M + 1, {-1, -1, -1});
  for (int i = 1; i <= M; ++i) {
    char c;
    int v1, v2;
    cin >> c >> v1 >> v2;
    initial[i] = c == 'R';
    adj[v1].push_back({i, 0});
    adj[v2].push_back({i, 1});
  }
  dp[1] = {N / 2, N / 2, N};
  dp[1][initial[1]] += N % 2;
  compute(0);
  debug(dp);
  for (int i = 1; i <= M; ++i) {
    cout << ((initial[i] + dp[i][2]) % 2 ? "R" : "L");
  }
}
