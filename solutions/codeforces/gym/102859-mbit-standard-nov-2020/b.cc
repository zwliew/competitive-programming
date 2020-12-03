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

  string s;
  while (cin >> s) {
    string res;
    char cur = 0;
    int cnt = 0;
    for (char c : s) {
      if (c != cur) {
        if (cnt == 2) {
          res += cur;
        } else {
          while (cnt--) {
            res += cur;
          }
        }
        cur = c;
        cnt = 0;
      }
      ++cnt;
    }
    if (cnt == 2) {
      res += cur;
    } else {
      while (cnt--) {
        res += cur;
      }
    }
    cout << res << " ";
  }
}
