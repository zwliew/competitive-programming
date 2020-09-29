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

  int t, n;
  cin >> t >> n;
  char c;
  cin >> c;
  vector<int> pos;
  if (c == 'A') {
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      pos.push_back(x);
    }
  } else {
    string s;
    cin >> s;
    int curNum = 0;
    for (char c : s) {
      if (isdigit(c)) {
        curNum = curNum * 10 + c - '0';
      } else {
        if (curNum) {
          pos.push_back(curNum);
        }
        curNum = 0;
      }
    }
  }

  sort(pos.begin(), pos.end());
  cout << max(pos[n - 1] - pos[1], pos[n - 2] - pos[0]) - n + 2;
}
