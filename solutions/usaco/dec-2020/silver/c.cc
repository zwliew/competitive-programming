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

int N;
vector<vector<int>> adj;
vector<int> timeToStop;
vector<array<int, 3>> pos;
void compute(int u) {
  if (timeToStop[u] < INT_MAX)
    return;
  int ux = pos[u][0];
  int uy = pos[u][1];
  int ud = pos[u][2];
  int firstStopper = -1;
  for (int i = 0; i < N; ++i) {
    int x = pos[i][0];
    int y = pos[i][1];
    int d = pos[i][2];
    bool ok = false;
    if (!ud && d && x > ux && y < uy && x - ux > uy - y) {
      ok = true;
    } else if (ud && !d && x < ux && y > uy && ux - x < y - uy) {
      ok = true;
    }

    if (ok) {
      compute(i);
      if (!ud && d && timeToStop[i] + y > uy && x - ux < timeToStop[u]) {
        timeToStop[u] = x - ux;
        firstStopper = i;
      } else if (ud && !d && timeToStop[i] + x > ux && y - uy < timeToStop[u]) {
        timeToStop[u] = y - uy;
        firstStopper = i;
      }
    }
  }

  if (firstStopper == -1) {
    timeToStop[u] = 1e9;
  } else {
    adj[firstStopper].push_back(u);
  }
}

void traverse(vector<int>& ans, int u) {
  if (ans[u] != -1) {
    return;
  }
  ans[u] = 0;
  for (int v : adj[u]) {
    traverse(ans, v);
    ans[u] += ans[v] + 1;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  cin >> N;
  timeToStop.assign(N, INT_MAX);
  adj.resize(N);
  for (int i = 0; i < N; ++i) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    bool d = c == 'N';
    pos.push_back({x, y, d});
  }

  for (int i = 0; i < N; ++i) {
    if (timeToStop[i] == INT_MAX) {
      compute(i);
    }
  }

  vector<int> ans(N, -1);
  for (int i = 0; i < N; ++i) {
    if (ans[i] == -1) {
      traverse(ans, i);
    }
  }
  for (int x : ans) {
    cout << x << "\n";
  }
}
