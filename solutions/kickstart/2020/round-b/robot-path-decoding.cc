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

int64_t R = 0;
int64_t C = 0;
const int64_t mod = 1e9;
string s;

void solve(int l, int r, int64_t mult) {
  if (l > r)
    return;

  if (s[l] >= '2' && s[l] <= '9') {
    int bal = 1;
    int closingIdx = l + 2;
    for (; bal; ++closingIdx) {
      if (s[closingIdx] == '(')
        ++bal;
      else if (s[closingIdx] == ')')
        --bal;
    }
    --closingIdx;
    solve(l + 2, closingIdx - 1, (mult * (s[l] - '0')) % mod);
    solve(closingIdx + 1, r, mult % mod);
    return;
  }

  int64_t dr = 0, dc = 0;
  if (s[l] == 'W') {
    --dc;
  } else if (s[l] == 'E') {
    ++dc;
  } else if (s[l] == 'N') {
    --dr;
  } else {
    ++dr;
  }
  R = ((R + dr * mult) % mod + mod) % mod;
  C = ((C + dc * mult) % mod + mod) % mod;

  solve(l + 1, r, mult % mod);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";

    cin >> s;
    R = 0;
    C = 0;
    solve(0, s.size() - 1, 1);

    cout << C + 1 << " " << R + 1 << "\n";
  }
}

