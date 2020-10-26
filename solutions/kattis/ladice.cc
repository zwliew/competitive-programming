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

int find(vector<int>& p, int u) {
  return u == p[u] ? u : p[u] = find(p, p[u]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, l;
  cin >> n >> l;
  vector<int> p(l);
  vector<bool> filled(l);
  iota(p.begin(), p.end(), 0);
  while (n--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    bool ok = false;
    int pa = find(p, a);
    int pb = find(p, b);
    if (!filled[a]) {
      filled[a] = true;
      ok = true;
      p[pa] = pb;
    } else if (!filled[b]) {
      filled[b] = true;
      ok = true;
      p[pb] = pa;
    } else if (!filled[pa]) {
      filled[pa] = true;
      ok = true;
      p[pa] = pb;
    } else if (!filled[pb]) {
      filled[pb] = true;
      ok = true;
      p[pb] = pa;
    }
    if (ok) {
      cout << "LADICA";
    } else {
      cout << "SMECE";
    }
    cout << "\n";
  }
}
