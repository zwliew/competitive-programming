#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int M;
  cin >> M;

  vector<int> cubes;
  for (int i = 1; i * i * i <= M; ++i) {
    cubes.push_back(i * i * i);
  }

  vector<int> cnt(M + 1);
  for (int i = 0; i < cubes.size(); ++i) {
    for (int j = i + 1; j < cubes.size() && cubes[i] + cubes[j] <= M; ++j) {
      cnt[cubes[i] + cubes[j]]++;
    }
  }

  for (int i = M; i >= 0; --i) {
    if (cnt[i] >= 2) {
      cout << i;
      return 0;
    }
  }
  cout << "none";
}
