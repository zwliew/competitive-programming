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

  int h, w;
  string chs;
  while (cin >> h >> w >> chs) {
    char ch = chs[1];
    pair<int, int> delta = {-1, -1};
    vector<pair<int, int>> coords;
    vector<vector<char>> res(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char cur;
        cin >> cur;
        if (cur == ch) {
          coords.emplace_back(i, j);
        } else {
          res[i][j] = cur;
        }
      }
    }

    bool found = false;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char cur;
        cin >> cur;
        if (!found && cur == ch) {
          delta = {i - coords[0].first, j - coords[0].second};
          found = true;
        } else if (cur != ch) {
          res[i][j] = cur;
        }
      }
    }

    for (auto& [r, c] : coords) {
      int nr = r + 2 * delta.first;
      int nc = c + 2 * delta.second;
      if (nr >= 0 && nc >= 0 && nr < h && nc < w) {
        res[nr][nc] = ch;
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << res[i][j];
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
