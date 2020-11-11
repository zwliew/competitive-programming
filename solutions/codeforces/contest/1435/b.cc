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
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> rows(N, vector<int>(M));
    for (auto& v : rows) {
      for (auto& x : v) {
        cin >> x;
      }
    }

    vector<int> order(N * M + 1);
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        int x;
        cin >> x;
        order[x] = j;
      }
    }

    sort(rows.begin(), rows.end(),
         [&](auto& x, auto& y) { return order[x[0]] < order[y[0]]; });

    for (auto& v : rows) {
      for (auto& x : v) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
}
