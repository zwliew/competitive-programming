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
#define FILE "buckets"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  pair<int, int> barn, lake, rock;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      char c;
      cin >> c;
      if (c == 'R') {
        rock = {i, j};
      } else if (c == 'L') {
        lake = {i, j};
      } else if (c == 'B') {
        barn = {i, j};
      }
    }
  }

  int d = abs(lake.second - barn.second) + abs(lake.first - barn.first);
  int br = abs(rock.first - barn.first) + abs(rock.second - barn.second);
  int rl = abs(lake.second - rock.second) + abs(lake.first - rock.first);
  if ((barn.first != lake.first && barn.second != lake.second) ||
      d != br + rl) {
    cout << d - 1;
  } else {
    cout << d + 1;
  }
}
