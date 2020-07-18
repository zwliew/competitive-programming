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
  vector<int> canOpen(1001);
  vector<int> needOpen(1001);
  vector<int> self(1001);
  while (n--) {
    int a, b;
    cin >> a >> b;
    canOpen[b]++;
    needOpen[a]++;
    if (a == b) {
      self[a]++;
    }
  }

  int sum = 0;
  for (int i = 1; i <= 1000; ++i) {
    if (!canOpen[i]) {
      sum += needOpen[i];
    }
    sum += self[i] == 1 && canOpen[i] == 1;
  }
  cout << sum;
}
