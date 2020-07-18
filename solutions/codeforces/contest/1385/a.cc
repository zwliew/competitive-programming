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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  while (t--) {
    int arr[3];
    for (int i = 0; i < 3; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + 3);

    if (arr[1] != arr[2]) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    cout << arr[0] << ' ' << arr[0] << ' ' << arr[2] << '\n';
  }
}
