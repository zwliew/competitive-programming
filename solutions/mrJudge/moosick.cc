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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "rblock"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Iterate through every window of size C and check if the frequencies and the
  // ranges of the elements in the window correspond to the target.
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int c;
  cin >> c;
  array<int, 89> t{}, cur{};
  int tmx = INT_MIN, tmn = INT_MAX;
  for (int i = 0; i < c; ++i) {
    int x;
    cin >> x;
    t[x]++;
    tmx = max(tmx, x);
    tmn = min(tmn, x);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    cur[a[i]]++;
    if (i >= c) {
      cur[a[i - c]]--;
    }

    if (i >= c - 1) {
      int cmx = INT_MIN, cmn = INT_MAX;
      for (int i = 0; i < 89; ++i) {
        if (cur[i]) {
          cmx = max(cmx, i);
          cmn = min(cmn, i);
        }
      }

      if (cmx - cmn == tmx - tmn) {
        bool ok = true;
        for (int i = cmn; i <= cmx; ++i) {
          if (cur[i] != t[i - cmn + tmn]) {
            ok = false;
            break;
          }
        }

        if (ok) {
          ans.push_back(i - c + 2);
        }
      }
    }
  }
  cout << ans.size() << "\n";
  for (int x : ans) {
    cout << x << "\n";
  }
}
