#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
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
#define FILE "pairup"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  array<int, 3> avail;
  cin >> avail[0] >> avail[1] >> avail[2];
  int m;
  cin >> m;
  vector<pair<int, bool>> mice(m);
  for (int i = 0; i < m; ++i) {
    int cost;
    string type;
    cin >> cost >> type;
    mice[i] = {cost, type != "USB"};
  }
  sort(mice.begin(), mice.end());

  int bought = 0;
  int64_t cost = 0;
  for (auto& [x, type] : mice) {
    if (avail[type] || avail[2]) {
      cost += x;
      ++bought;
      --avail[avail[type] ? type : 2];
    }
  }
  cout << bought << " " << cost;
}
