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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<string> kb = {
      "`1234567890-=",
      "QWERTYUIOP[]\\",
      "ASDFGHJKL;'",
      "ZXCVBNM,./",
  };

  auto search = [&](char c) {
    for (int i = 0; i < kb.size(); ++i) {
      for (int j = 0; j < kb[i].size(); ++j) {
        if (kb[i][j] == c) {
          return make_pair(i, j);
        }
      }
    }
    return make_pair(-1, -1);
  };

  string line;
  while (getline(cin, line)) {
    for (char c : line) {
      if (c == ' ') {
        cout << c;
        continue;
      }

      auto pos = search(c);
      assert(pos.first != -1);
      assert(pos.second != -1);
      cout << kb[pos.first][pos.second - 1];
    }
    cout << "\n";
  }
}
