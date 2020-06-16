/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<tuple<int, int, int>> customers(n);
  for (int i = 0; i < n; ++i) {
    int s, e;
    cin >> s >> e;
    customers[i] = {s, e, i};
  }

  sort(customers.begin(), customers.end());

  vector<int> ans(n);
  set<pair<int, int>> rooms;
  for (int i = 0; i < n; ++i) {
    auto &[s, e, idx] = customers[i];
    auto it = rooms.lower_bound({s + 1, 0});
    if (it == rooms.begin()) {
      rooms.emplace(e + 1, rooms.size() + 1);
      ans[idx] = rooms.size();
    } else {
      it = prev(it);
      ans[idx] = it->second;
      rooms.emplace(e + 1, it->second);
      rooms.erase(it);
    }
  }

  cout << *max_element(ans.begin(), ans.end()) << '\n';
  for (auto x : ans) cout << x << '\n';
}
