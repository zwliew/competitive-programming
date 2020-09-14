#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
      cin >> x;

    int cd = 0;
    for (int i = 0; i < n; ++i) {
      int cand = i;
      int candCd = gcd(cd, a[i]);
      for (int j = i + 1; j < n; ++j) {
        int nxtCd = gcd(cd, a[j]);
        if (nxtCd > candCd) {
          candCd = nxtCd;
          cand = j;
        }
      }
      swap(a[i], a[cand]);
      cd = candCd;
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}

