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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Normalize the times and sort them
  // Need to be wary of edge cases involving 12.xx am/pm
  int n;
  while (cin >> n && n) {
    vector<pair<int, string>> v;
    string a, b;
    while (n--) {
      cin >> a >> b;
      int pos = a.find(":");
      int t = stoi(a.substr(0, pos)) * 100 + stoi(a.substr(pos + 1));
      if (b == "p.m." && t < 1200) {
        t += 1200;
      } else if (b == "a.m." && t >= 1200) {
        t -= 1200;
      }
      v.emplace_back(t, a + " " + b);
      debug(a + " " + b, t);
    }
    sort(v.begin(), v.end());
    for (auto& [_, x] : v) {
      cout << x << '\n';
    }
    cout << '\n';
  }
}
