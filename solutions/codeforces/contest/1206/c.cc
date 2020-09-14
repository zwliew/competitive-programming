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

  int n;
  cin >> n;

  if (n % 2 == 0) {
    cout << "NO";
    return 0;
  }

  vector<int> a(2 * n);
  for (int i = 0; i < n; ++i) {
    a[i] = i * 2 + 1;
    a[i + n] = i * 2 + 2;
    if (i % 2)
      swap(a[i], a[i + n]);
  }
  
  cout << "YES\n";
  for (int x : a) {
    cout << x << ' ';
  }
}
