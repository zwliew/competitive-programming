/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

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

  int x;
  cin >> x;
  vector<int> ref(10);
  int i = x;
  int pw = 1;
  do {
    ref[i % 10]++;
    pw *= 10;
    i /= 10;
  } while (i);

  for (i = x + 1; i < pw; ++i) {
    vector<int> cnt(10);
    int j = i;
    do {
      cnt[j % 10]++;
      j /= 10;
    } while (j);
    if (cnt == ref) {
      cout << i;
      return 0;
    }
  }
  cout << 0;

  // Alternative
  //   string x;
  //   cin >> x;
  //   string orig = x;
  //   string ans;
  //   do {
  //     if (x > orig && (x < ans || ans.empty())) {
  //       ans = x;
  //     }
  //   } while (next_permutation(x.begin(), x.end()));

  //   if (ans.empty()) {
  //     cout << 0;
  //   } else {
  //     cout << ans;
  //   }
}
