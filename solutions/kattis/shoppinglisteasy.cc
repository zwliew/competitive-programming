#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M;
  cin >> N >> M;
  map<string, int> cnt;
  for (int i = 0; i < N; ++i) {
    unordered_set<string> seen;
    for (int j = 0; j < M; ++j) {
      string name;
      cin >> name;
      seen.insert(name);
    }

    for (auto &x : seen) {
      cnt[x]++;
    }
  }

  vector<string> ans;
  for (auto &[k, v] : cnt) {
    if (v == N) {
      ans.push_back(k);
    }
  }

  cout << ans.size() << "\n";
  for (auto &x : ans) {
    cout << x << "\n";
  }
}
