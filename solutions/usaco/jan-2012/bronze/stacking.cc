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

  int n, k;
  cin >> n >> k;

  vector<int> diff(n + 1);
  for (int i = 0; i < k; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    diff[l]++;
    diff[r]--;
  }
  partial_sum(diff.begin(), diff.end(), diff.begin());
  nth_element(diff.begin(), diff.begin() + n / 2, diff.end() - 1);
  cout << diff[n / 2];
}
