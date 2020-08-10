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
#define FILE "cbarn"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> w(n * 2);
  for (auto& x : w)
    cin >> x;
  sort(w.begin(), w.end());

  int ans = INT_MAX;
  for (int i = 0; i < n * 2; ++i) {
    for (int j = i + 1; j < n * 2; ++j) {
      int cur = 0;
      vector<bool> paired(n * 2);
      paired[i] = true;
      paired[j] = true;
      for (int k = 0; k < n * 2; ++k) {
        if (paired[k])
          continue;
        paired[k] = true;
        for (int l = k + 1; l < n * 2; ++l) {
          if (!paired[l]) {
            paired[l] = true;
            cur += w[l] - w[k];
            k = l;
            break;
          }
        }
      }
      // Alternative, more straightforward method of summing pairs, albeit
      // slower.
      // multiset<int> unpaired(w.begin(), w.end());
      // unpaired.erase(unpaired.find(w[i]));
      // unpaired.erase(unpaired.find(w[j]));
      // while (!unpaired.empty()) {
      //   cur -= *unpaired.begin();
      //   unpaired.erase(unpaired.begin());
      //   cur += *unpaired.begin();
      //   unpaired.erase(unpaired.begin());
      // }
      ans = min(ans, cur);
    }
  }
  cout << ans;
}
