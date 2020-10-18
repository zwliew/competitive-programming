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

  int n, m, p;
  cin >> n >> m >> p;
  vector<pair<int, int>> judges(n), repos(m), storehouses(p);
  for (auto& [x, y] : judges)
    cin >> x >> y;
  for (auto& [x, y] : repos)
    cin >> x >> y;
  for (auto& [x, y] : storehouses)
    cin >> x >> y;

  vector<tuple<int, int, int>> distances;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = judges[i].first - repos[j].first;
      int y = judges[i].second - repos[j].second;
      distances.emplace_back(x * x + y * y, i, j);
    }
  }
  sort(distances.begin(), distances.end());

  double total = 0;
  vector<bool> usedJudge(n), usedRepo(m);
  for (auto& [d, i, j] : distances) {
    if (usedJudge[i] || usedRepo[j]) {
      continue;
    }
    usedJudge[i] = true;
    usedRepo[j] = true;
    total += sqrt(d);
  }

  distances.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j) {
      int x = judges[i].first - storehouses[j].first;
      int y = judges[i].second - storehouses[j].second;
      distances.emplace_back(x * x + y * y, i, j);
    }
  }
  sort(distances.begin(), distances.end());

  usedJudge.assign(n, 0);
  usedRepo.assign(p, 0);
  for (auto& [d, i, j] : distances) {
    if (usedJudge[i] || usedRepo[j])
      continue;
    usedJudge[i] = true;
    usedRepo[j] = true;
    total += sqrt(d);
  }

  cout << fixed << setprecision(6) << total;
}
