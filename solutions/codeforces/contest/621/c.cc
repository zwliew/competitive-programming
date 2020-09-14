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
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Pretty straightforward probability and number theory.
  // 1. The product of a pair of integers is divisible by a prime p only if at
  // least one of integers is divisible by p.
  //
  // 2. The number of multiples of p in the range [l, r] = number of multiples
  // in the range [1, r] - number of multiples in the range [1, l - 1].
  //
  // 3a. Use the Principle of Inclusion-Exclusion to count the number of pairs
  // divisible by p.
  // 3b. Alternatively, and more simply, count the number of pairs _not_
  // divisible by p and subtract that from the total number of pairs.
  int n, p;
  cin >> n >> p;
  vector<pair<double, double>> sharks(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    sharks[i].first = r - l + 1;
    sharks[i].second = r / p - (l - 1) / p;
  }

  double ans = (sharks[0].second * sharks[n - 1].first +
                sharks[0].first * sharks[n - 1].second -
                sharks[0].second * sharks[n - 1].second) /
               sharks[0].first / sharks[n - 1].first;
  for (int i = 0; i < n - 1; ++i) {
    ans += (sharks[i].second * sharks[i + 1].first +
            sharks[i].first * sharks[i + 1].second -
            sharks[i].second * sharks[i + 1].second) /
           sharks[i].first / sharks[i + 1].first;
  }
  cout << fixed << setprecision(6) << ans * 2000;
}
