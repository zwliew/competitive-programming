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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

  int N;
  double P, S, V;
  cin >> N >> P >> S >> V;

  double sqrt2 = sqrt(2);
  double log2N = log2(N);
  double fc = N / P / 1e9;
  double sc = S / V;
  auto f = [&](double c) {
    return fc * pow(log2N, c * sqrt2) + sc * (1 + 1 / c);
  };

  double l = 0, r = 100;
  for (int i = 0; i < 50; ++i) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  cout << fixed << setprecision(6) << f(l) << " " << l;
}
