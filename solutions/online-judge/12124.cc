/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  while (t--) {
    int n, b;
    cin >> n >> b;

    vector<vector<pair<int, int>>> prices;
    unordered_map<string, int> ntoi;
    while (n--) {
      string name, type;
      int p, q;
      cin >> name >> type >> p >> q;
      if (!ntoi.count(name)) {
        ntoi[name] = (int)ntoi.size();
      }
      if ((int)prices.size() == ntoi[name]) {
        prices.resize(prices.size() + 1);
      }

      prices[ntoi[name]].emplace_back(q, p);
    }

    int lo = 0, hi = 1e9;
    int ans = 0;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      long long spending = 0;
      for (auto &p : prices) {
        int minp = INT_MAX;
        for (auto &[quality, price] : p) {
          if (quality >= mid) {
            minp = min(minp, price);
          }
        }
        if (minp > b) {
          spending = b + 1;
          break;
        }
        spending += minp;
      }
      if (spending <= b) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    cout << ans << '\n';
  }
}
