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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> prefGcd(n), sufGcd(n);
  for (auto& x : a) {
    cin >> x;
  }

  prefGcd[0] = a[0];
  for (int i = 1; i < n; ++i) {
    prefGcd[i] = gcd(prefGcd[i - 1], a[i]);
  }
  sufGcd[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    sufGcd[i] = gcd(sufGcd[i + 1], a[i]);
  }

  if (n == 1) {
    cout << "YES";
  } else if (!k) {
    cout << (prefGcd[n - 1] > 1 ? "YES" : "NO");
  } else if (k % 2 == 0) {
    cout << "NO";
  } else {
    for (int i = 0; i < n; ++i) {
      int pref = i ? prefGcd[i - 1] : 0;
      int suf = i < n - 1 ? sufGcd[i + 1] : 0;
      if (gcd(pref, suf) > 1) {
        cout << "YES";
        return 0;
      }
    }
    cout << "NO";
  }
}

