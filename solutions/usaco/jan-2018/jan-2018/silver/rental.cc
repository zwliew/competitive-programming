/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "rental"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m, r;
  cin >> n >> m >> r;
  vector<int> cows(n);
  vector<pair<int, int>> buy(m);
  vector<int> rent(r);
  for (int i = 0; i < n; ++i) {
    cin >> cows[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> buy[i].second >> buy[i].first;
  }
  for (int i = 0; i < r; ++i) {
    cin >> rent[i];
  }

  sort(cows.rbegin(), cows.rend());
  sort(buy.rbegin(), buy.rend());
  sort(rent.rbegin(), rent.rend());

  vector<int64_t> totalRent = {0};
  for (int i = 0; i < n; ++i) {
    totalRent.emplace_back(totalRent.back() + (i < r ? rent[i] : 0));
  }

  vector<int64_t> totalBuy = {0};
  int j = 0;
  for (int i = 0; i < n; ++i) {
    int64_t earnings = 0;
    while (cows[i] && j < m) {
      int amt = min(cows[i], buy[j].second);
      earnings += (int64_t)amt * buy[j].first;
      cows[i] -= amt;
      buy[j].second -= amt;
      if (!buy[j].second) {
        ++j;
      }
    }
    totalBuy.emplace_back(totalBuy.back() + earnings);
  }

  int64_t best = 0;
  for (int i = 0; i <= n; ++i) {
    best = max(best, totalBuy[i] + totalRent[n - i]);
  }
  cout << best;
}
