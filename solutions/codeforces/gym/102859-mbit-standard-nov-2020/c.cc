#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, M;
  cin >> N >> M;
  vector<int> ans;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int f = (N - i - 1) * M;
      if ((N - i - 1) % 2 == 0) {
        f += M - j - 1;
      } else {
        f += j;
      }

      int s = j * N;
      if (j % 2) {
        s += N - i - 1;
      } else {
        s += i;
      }
      debug(f, s);
      if (f == s) {
        ans.push_back(f + 1);
      }
    }
  }
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << " ";
  }
}
