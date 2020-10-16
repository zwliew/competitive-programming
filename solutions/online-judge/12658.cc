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

  int n;
  cin >> n;
  vector<vector<char>> grid(5, vector<char>(4 * n));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4 * n; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<string>> nums = {
      {
          ".*.",
          ".*.",
          ".*.",
          ".*.",
          ".*.",
      },
      {
          "***",
          "..*",
          "***",
          "*..",
          "***",
      },
      {
          "***",
          "..*",
          "***",
          "..*",
          "***",
      },
  };

  auto matches = [&](int c, vector<string>& num) {
    for (int i = 0; i < 5; ++i) {
      for (int j = c; j < c + 3; ++j) {
        if (num[i][j - c] != grid[i][j]) {
          return false;
        }
      }
    }
    return true;
  };

  int ans = 0;
  for (int i = 0; i < 4 * n; i += 4) {
    for (int j = 0; j < 3; ++j) {
      if (matches(i, nums[j])) {
        ans *= 10;
        ans += j + 1;
        break;
      }
    }
  }

  cout << ans << "\n";
}
