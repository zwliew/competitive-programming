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

  const int MAXN = 32000;
  vector<bool> p(MAXN + 1, true);
  for (int i = 2; i * i <= MAXN; ++i) {
    if (p[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        p[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= MAXN; ++i) {
    if (p[i])
      primes.push_back(i);
  }

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    vector<int> ans;
    for (int y : primes) {
      if (y * 2 > x)
        break;
      if (p[x - y]) {
        ans.push_back(y);
      }
    }
    cout << x << " has " << ans.size() << " representation(s)\n";
    for (int y : ans) {
      cout << y << "+" << x - y << "\n";
    }
    cout << "\n";
  }
}
