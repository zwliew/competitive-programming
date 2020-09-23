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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  sort(a.rbegin(), a.rend());

  int smallestIdx = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0 && (smallestIdx == -1 || a[smallestIdx] > a[i])) {
      smallestIdx = i;
    }
  }

  if (smallestIdx == -1) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (i != smallestIdx) {
      cout << a[i];
    }
  }
  cout << a[smallestIdx];
}

