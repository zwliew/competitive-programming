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

  int N;
  cin >> N;
  vector<int> P(N);
  for (auto& x : P)
    cin >> x;

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int sum = 0;
    unordered_set<int> seen;
    for (int j = i; j < N; ++j) {
      sum += P[j];
      seen.insert(P[j]);
      if (sum % (j - i + 1) == 0 && seen.count(sum / (j - i + 1))) {
        ++ans;
      }
    }
  }
  cout << ans;
}
