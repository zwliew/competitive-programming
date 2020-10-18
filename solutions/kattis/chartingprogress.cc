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

  string s;
  while (getline(cin, s)) {
    int len = s.size();
    vector<int> counts;
    int cnt = 0;
    for (char c : s) {
      if (c == '*')
        ++cnt;
    }
    counts.emplace_back(cnt);
    while (getline(cin, s) && s.size()) {
      cnt = 0;
      for (char c : s) {
        if (c == '*')
          ++cnt;
      }
      counts.emplace_back(cnt);
    }

    int pref = len;
    for (int x : counts) {
      pref -= x;
      for (int i = 0; i < pref; ++i) {
        cout << ".";
      }
      for (int i = 0; i < x; ++i) {
        cout << "*";
      }
      for (int i = 0; i < len - pref - x; ++i) {
        cout << ".";
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
