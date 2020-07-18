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

  int n;
  cin >> n;
  vector<int> cnt(101);
  while (n--) {
    int x;
    cin >> x;
    cnt[x]++;
    
    if (x == 50) {
      if (cnt[25] < 1) {
        cout << "NO";
        return 0;
      }
      cnt[25]--;
    } else if (x == 100) {
      if (cnt[50] && cnt[25]) {
        cnt[50]--;
        cnt[25]--;
      } else if (cnt[25] >= 3) {
        cnt[25] -= 3;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
