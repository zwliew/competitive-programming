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
#define FILE "notlast"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  unordered_map<string, int> cnt;
  cnt["Bessie"] = 0;
  cnt["Elsie"] = 0;
  cnt["Daisy"] = 0;
  cnt["Gertie"] = 0;
  cnt["Annabelle"] = 0;
  cnt["Maggie"] = 0;
  cnt["Henrietta"] = 0;

  while (n--) {
    string s;
    int x;
    cin >> s >> x;
    cnt[s] += x;
  }

  vector<pair<int, string>> sorted;
  for (auto& p : cnt) {
    sorted.emplace_back(p.second, p.first);
  }
  sort(sorted.begin(), sorted.end());

  int mn = sorted.front().first;
  const string estr = "";
  auto it = lower_bound(sorted.begin(), sorted.end(), make_pair(mn + 1, estr));
  if (next(it) == sorted.end() || next(it)->first > it->first) {
    cout << it->second;
  } else {
    cout << "Tie";
  }
}
