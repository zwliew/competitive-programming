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

  // Simulate the process and use trigonometric functions
  const long double pi = 3.14159265359;
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;

    long double angle = 90;
    long double x = 0, y = 0;
    while (m--) {
      long double a, d;
      cin >> a >> d;

      angle = fmod(angle + a + 360, 360);
      x += cos(angle * pi / 180) * d;
      y += sin(angle * pi / 180) * d;
    }

    cout << fixed << setprecision(3) << x << ' ' << y << '\n';
  }
}
