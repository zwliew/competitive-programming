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
#define FILE "countcross"
#endif

struct Road {
  int r1, c1, r2, c2;
  Road(int a, int b, int c, int d) : r1(a), c1(b), r2(c), c2(d) {}
  bool operator<(const Road& other) const {
    return tie(r1, c1, r2, c2) < tie(other.r1, other.c1, other.r2, other.c2);
  }
};

set<Road> roads;
vector<vector<bool>> vis, cows;
int n, cnt;

bool valid(int r, int c) {
  return r >= 0 && c >= 0 && r < n && c < n;
}

void dfs(int r, int c) {
  if (vis[r][c])
    return;
  vis[r][c] = true;
  cnt += cows[r][c];
  if (valid(r + 1, c) && !roads.count({r, c, r + 1, c})) {
    dfs(r + 1, c);
  }
  if (valid(r - 1, c) && !roads.count({r, c, r - 1, c})) {
    dfs(r - 1, c);
  }
  if (valid(r, c + 1) && !roads.count({r, c, r, c + 1})) {
    dfs(r, c + 1);
  }
  if (valid(r, c - 1) && !roads.count({r, c, r, c - 1})) {
    dfs(r, c - 1);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < r; ++i) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1, --c1, --r2, --c2;
    roads.emplace(r1, c1, r2, c2);
    roads.emplace(r2, c2, r1, c1);
  }

  vector<int> cr(k), cc(k);
  cows.assign(n, vector<bool>(n));
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    cows[r][c] = true;
    cr[i] = r;
    cc[i] = c;
  }

  vector<int> compSz;
  vis.assign(n, vector<bool>(n));
  for (int i = 0; i < k; ++i) {
    if (!vis[cr[i]][cc[i]]) {
      cnt = 0;
      dfs(cr[i], cc[i]);
      compSz.push_back(cnt);
    }
  }

  int ans = 0;
  for (int i = 0; i < compSz.size(); ++i) {
    for (int j = i + 1; j < compSz.size(); ++j) {
      ans += compSz[i] * compSz[j];
    }
  }
  cout << ans;
}
