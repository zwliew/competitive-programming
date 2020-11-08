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

  int N;
  cin >> N;
  vector<pair<int, int>> prev;
  for (int i = 0; i < N; ++i) {
    int x, d;
    cin >> x >> d;
    if (d) {
      prev.emplace_back(x, 1);
    } else {
      while (x && prev.size() && prev.back().second) {
        if (prev.back().first > x) {
          prev.back().first -= x;
          x = 0;
        } else {
          x -= prev.back().first;
          prev.pop_back();
        }
      }
      if (x) {
        prev.emplace_back(x, 0);
      }
    }
  }

  cout << prev.size() << "\n";
  for (auto& [a, b] : prev) {
    cout << a << " " << b << "\n";
  }
}
