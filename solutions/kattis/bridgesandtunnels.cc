#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

class union_find {
 private:
  vector<int> rep, cnt;

 public:
  union_find(int N) {
    rep.resize(N);
    iota(rep.begin(), rep.end(), 0);
    cnt.assign(N, 1);
  }

  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    rep[u] = v;
    cnt[v] += cnt[u];
  }

  int find(int u) { return rep[u] == u ? u : rep[u] = find(rep[u]); }

  int size(int u) { return cnt[find(u)]; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  union_find uf(N * 2);
  unordered_map<string, int> nameMap;
  int ctr = 0;
  while (N--) {
    string u, v;
    cin >> u >> v;
    if (!nameMap.count(u)) {
      nameMap[u] = ctr++;
    }
    if (!nameMap.count(v)) {
      nameMap[v] = ctr++;
    }
    uf.join(nameMap[u], nameMap[v]);
    cout << uf.size(nameMap[v]) << "\n";
  }
}
