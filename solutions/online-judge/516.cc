/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <ext/numeric>
#include "bits/stdc++.h"

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

  string s;
  while (getline(cin, s) && s != "0") {
    stringstream ss(s);
    int p, e;
    int n = 1;
    while (ss >> p >> e) {
      n *= __gnu_cxx::power(p, e);
    }

    --n;
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        int cnt = 0;
        while (n % i == 0) {
          n /= i;
          ++cnt;
        }
        factors.emplace_back(i, cnt);
      }
    }
    if (n > 1) {
      factors.emplace_back(n, 1);
    }

    reverse(factors.begin(), factors.end());
    bool first = true;
    for (auto& [p, e] : factors) {
      if (!first) {
        cout << " ";
      }
      first = false;
      cout << p << " " << e;
    }
    cout << "\n";
  }
}
