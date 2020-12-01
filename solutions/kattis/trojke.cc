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

  int N;
  cin >> N;
  vector<pair<int, int>> pos;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      if (c != '.') {
        pos.emplace_back(i, j);
      }
    }
  }

  int count = 0;
  for (int i = 0; i < pos.size(); ++i) {
    for (int j = i + 1; j < pos.size(); ++j) {
      for (int k = j + 1; k < pos.size(); ++k) {
        if ((pos[j].second - pos[i].second) * (pos[k].first - pos[j].first) ==
            (pos[k].second - pos[j].second) * (pos[j].first - pos[i].first)) {
          ++count;
        }
      }
    }
  }
  cout << count;
}
