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
#define FILE "berries"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // For each problem, check if every test case satisfies the constraints
  int p, t;
  cin >> p >> t;
  int ans = 0;
  while (p--) {
    bool ok = true;
    for (int i = 0; i < t; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); ++j) {
        if (j && tolower(s[j]) != s[j]) {
          ok = false;
          break;
        }
      }
    }
    ans += ok;
  }
  cout << ans;
}
