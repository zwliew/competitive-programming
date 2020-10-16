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

  // Max number of minutes is small.
  int s[2], t[2];
  string x;
  cin >> x;
  s[0] = stoi(x.substr(0, 2)) * 60 + stoi(x.substr(3));
  cin >> x;
  s[1] = stoi(x.substr(0, 2)) * 60 + stoi(x.substr(3));
  cin >> x;
  t[0] = stoi(x.substr(0, 2)) * 60 + stoi(x.substr(3));
  cin >> x;
  t[1] = stoi(x.substr(0, 2)) * 60 + stoi(x.substr(3));

  bool vis[(int)1e7];
  memset(vis, 0, sizeof vis);
  for (int i = s[0]; i < 1e7; i += t[0]) {
    vis[i] = true;
  }
  vector<string> days = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                         "Wednesday", "Thursday", "Friday"};
  for (int i = s[1]; i < 1e7; i += t[1]) {
    if (vis[i]) {
      int h = (i / 60) % 24;
      int m = i % 60;
      cout << days[(i / 1440) % 7] << "\n"
           << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m;
      return 0;
    }
  }
  cout << "Never";
}
