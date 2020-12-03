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

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

unordered_map<string, string> mp;
vector<int> dp;
string s;

int backtrack(int i) {
  if (i == s.size())
    return 0;
  auto& ans = dp[i];
  if (ans != -2) {
    return ans;
  }

  for (int j = 1; j <= 3 && i + j <= s.size(); ++j) {
    string t = s.substr(i, j);
    if (mp.count(t)) {
      int cur = backtrack(i + j);
      if (cur != -1) {
        return ans = j;
      }
    }
  }
  return ans = -1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  for (int i = 0; i <= 9; ++i) {
    int p = i * i;
    mp[to_string(p)] = to_string(i);
    mp[to_string(p * i)] = to_string(i);
  }

  cin >> s;
  dp.assign(s.size(), -2);

  if (backtrack(0) == -1) {
    cout << -1;
    return 0;
  }

  string ans;
  for (int i = 0; i < s.size(); i += dp[i]) {
    ans += mp[s.substr(i, dp[i])];
  }
  cout << ans;
}
