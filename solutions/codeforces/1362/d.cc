/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

#define f first
#define s second
#define eb emplace_back

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, m;
  cin >> n >> m;
  vector<vi> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].eb(b);
    adj[b].eb(a);
  }

  vector<unordered_set<int>> covered(n + 1);
  vi curIdx(n + 1, 1);
  vector<vi> topics(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    topics[x].eb(i + 1);
  }

  vi ans;
  for (int i = 1; i <= n; ++i) {
    for (auto a : topics[i]) {
      while (curIdx[a] <= n && covered[a].count(curIdx[a]))
        ++curIdx[a];
      if (curIdx[a] > n || curIdx[a] != i) {
        cout << -1;
        return 0;
      }
      for (auto b : adj[a]) {
        covered[b].emplace(curIdx[a]);
      }
      ans.eb(a);
    }
  }

  for (auto x : ans) {
    cout << x << ' ';
  }
}

