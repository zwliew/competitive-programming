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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Straightforward implementation problem
  const vector<string> keys = {
      "qwertyuiop",
      "asdfghjkl",
      "zxcvbnm",
  };

  auto findPos = [&](char c) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < keys[i].size(); ++j) {
        if (keys[i][j] == c) {
          return make_pair(i, j);
        }
      }
    }
    return make_pair(-1, -1);
  };

  int t;
  cin >> t;
  while (t--) {
    string s;
    int k;
    cin >> s >> k;
    vector<pair<int, string>> candidates(k);
    for (int i = 0; i < k; ++i) {
      cin >> candidates[i].second;
      for (int j = 0; j < candidates[i].second.size(); ++j) {
        auto typo = findPos(candidates[i].second[j]);
        auto orig = findPos(s[j]);
        candidates[i].first +=
            abs(typo.first - orig.first) + abs(typo.second - orig.second);
      }
    }
    sort(candidates.begin(), candidates.end());

    for (auto& [x, y] : candidates) {
      cout << y << " " << x << "\n";
    }
  }
}
