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

  unordered_map<string, int> mp = {
      {"upper", 0},
      {"middle", 1},
      {"lower", 2},
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<vector<int>, string>> people(n);
    for (auto& [x, y] : people) {
      string tmp;
      cin >> y >> tmp;
      y.pop_back();
      istringstream ss(tmp);
      while (getline(ss, tmp, '-')) {
        x.emplace_back(mp[tmp]);
      }
      reverse(x.begin(), x.end());
      while (x.size() < 10) {
        x.emplace_back(1);
      }
      cin >> tmp;
    }

    sort(people.begin(), people.end(), [](auto& x, auto& y) {
      int i;
      for (i = 0; i < 10; ++i) {
        if (x.first[i] != y.first[i]) {
          return x.first[i] < y.first[i];
        }
      }
      return x.second < y.second;
    });

    for (auto& [x, y] : people) {
      cout << y << "\n";
    }
    for (int i = 0; i < 30; ++i) {
      cout << "=";
    }
    cout << "\n";
  }
}
