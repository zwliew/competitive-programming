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
//#include "bits/stdc++.h"

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

  // Parse the input and check for divisibility by 6
  const vector<vector<string>> digits = {
      {
          "***",
          "* *",
          "* *",
          "* *",
          "***",
      },
      {
          "  *",
          "  *",
          "  *",
          "  *",
          "  *",
      },
      {
          "***",
          "  *",
          "***",
          "*  ",
          "***",
      },
      {
          "***",
          "  *",
          "***",
          "  *",
          "***",
      },
      {
          "* *",
          "* *",
          "***",
          "  *",
          "  *",
      },
      {
          "***",
          "*  ",
          "***",
          "  *",
          "***",
      },
      {
          "***",
          "*  ",
          "***",
          "* *",
          "***",
      },
      {
          "***",
          "  *",
          "  *",
          "  *",
          "  *",
      },
      {
          "***",
          "* *",
          "***",
          "* *",
          "***",
      },
      {
          "***",
          "* *",
          "***",
          "  *",
          "***",
      },
  };

  vector<string> grid;
  string s;
  while (getline(cin, s)) {
    grid.push_back(s);
  }

  int total = 0;
  for (int c = 0; c < (int)grid[0].size(); c += 4) {
    vector<string> cur(5);
    for (int r = 0; r < 5; ++r) {
      cur[r] = grid[r].substr(c, 3);
    }
    int num = find(digits.begin(), digits.end(), cur) - digits.begin();
    if (num == 10) {
      cout << "BOOM!!";
      return 0;
    }
    total = total * 10 + num;
  }

  cout << (total % 6 == 0 ? "BEER!!" : "BOOM!!");
}
