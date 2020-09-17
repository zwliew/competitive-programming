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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }
  int n, k;
  cin >> n >> k;
  vector<int> pos(n);
  for (auto& x : pos)
    cin >> x;
  sort(pos.begin(), pos.end());

  int ans = 0;

  // Brute force folding at a knot or between 2 knots and check if the other
  // knots line up
  //
  // for (int i = 1; i < n - 1; ++i) {
  //   int l = i - 1;
  //   int r = i + 1;
  //   bool ok = true;
  //   while (l >= 0 && r < n) {
  //     if (pos[i] - pos[l] != pos[r] - pos[i]) {
  //       ok = false;
  //       break;
  //     }
  //     --l;
  //     ++r;
  //   }
  //   if (ok)
  //     ++ans;
  // }
  // for (int i = 1; i < n; ++i) {
  //   int l = i - 1;
  //   int r = i;
  //   bool ok = true;
  //   double x = (double)(pos[r] + pos[l]) / 2;
  //   while (l >= 0 && r < n) {
  //     if (x - pos[l] != pos[r] - x) {
  //       ok = false;
  //       break;
  //     }
  //     --l;
  //     ++r;
  //   }
  //   if (ok)
  //     ++ans;
  // }

  // Editorial solution: convert the array into a adjacent-pairwise difference
  // array, and count the number of prefix palindromes and suffix palindromes.
  auto isPalindrome = [&](int l, int r) {
    for (int i = l, j = r; i <= j; ++i, --j) {
      if (pos[i] != pos[j])
        return false;
    }
    return true;
  };
  for (int i = 0; i < n - 1; ++i) {
    pos[i] = pos[i + 1] - pos[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    if (isPalindrome(0, i))
      ++ans;
  }
  for (int i = 1; i < n - 1; ++i) {
    if (isPalindrome(i, n - 2))
      ++ans;
  }

  cout << ans;
}
