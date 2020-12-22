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
#define FILE "traffic"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<array<int, 3>> segments(N);
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s >> segments[i][1] >> segments[i][2];
    int res = 0;
    if (s == "on") {
      res = 1;
    } else if (s == "off") {
      res = 2;
    }
    segments[i][0] = res;
  }

  int mx = 1e9;
  int mn = -1e9;
  for (int i = N - 1; i >= 0; --i) {
    int x = segments[i][0];
    int l = segments[i][1];
    int r = segments[i][2];
    if (x == 0) {
      mx = min(mx, r);
      mn = max(mn, l);
    } else if (x == 1) {
      mx -= l;
      mn -= r;
      mn = max(0, mn);
    } else {
      mx += r;
      mn += l;
    }
  }

  cout << mn << " " << mx << "\n";

  for (int i = 0; i < N; ++i) {
    int x = segments[i][0];
    int l = segments[i][1];
    int r = segments[i][2];
    if (x == 0) {
      mx = min(mx, r);
      mn = max(mn, l);
    } else if (x == 1) {
      mx += r;
      mn += l;
    } else {
      mx -= l;
      mn -= r;
      mn = max(0, mn);
    }
  }
  cout << mn << " " << mx;
}
