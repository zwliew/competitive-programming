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

  unordered_map<char, int> fmp = {
      {'$', 0},
      {'|', 1},
      {'*', 2},
  };
  unordered_map<char, int> smp = {
      {'t', 1},
      {'b', 0},
      {'j', 2},
  };

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    stack<int> prev;
    bool ok = true;
    for (char c : s) {
      if (fmp.count(c)) {
        prev.push(fmp[c]);
      } else if (smp.count(c)) {
        while (prev.size() && prev.top() != smp[c]) {
          prev.pop();
        }
        if (prev.size()) {
          prev.pop();
        } else {
          ok = false;
        }
      }
    }

    if (ok && prev.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
