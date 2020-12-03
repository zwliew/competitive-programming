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

  int N;
  cin >> N;
  vector<int> A(N);
  int64_t l = 0, r = 0;
  for (auto& x : A) {
    cin >> x;
    r += x;
  }
  sort(A.begin(), A.end());

  double ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    r -= A[i];
    l += A[i];
    ans = max(ans, abs((double)l / (i + 1) - (double)r / (N - i - 1)));
  }
  cout << fixed << setprecision(6) << ans;
}
