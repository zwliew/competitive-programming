/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "evolution"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  unordered_map<string, set<int>> m;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      string s;
      cin >> s;
      m[s].emplace(i);
    }
  }

  for (auto& f : m) {
    for (auto& s : m) {
      vector<int> intersection;
      set_intersection(f.second.begin(), f.second.end(), s.second.begin(),
                       s.second.end(), back_inserter(intersection));
      if (intersection.size() &&
          intersection.size() != min(f.second.size(), s.second.size())) {
        cout << "no";
        return 0;
      }
    }
  }
  cout << "yes";
}
