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
#define FILE "lifeguards"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> endpoints;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    endpoints.emplace_back(a, i);
    endpoints.emplace_back(b, i);
  }
  sort(endpoints.begin(), endpoints.end());

  unordered_set<int> lifeguards;
  vector<int> alone(n);
  int total = 0;
  int prev = 0;
  for (int i = 0; i < n * 2; ++i) {
    int t = endpoints[i].first;
    int idx = endpoints[i].second;

    if (lifeguards.size()) {
      total += t - prev;
    }

    if (lifeguards.size() == 1) {
      alone[*lifeguards.begin()] += t - prev;
    }

    if (!lifeguards.count(idx)) {
      lifeguards.emplace(idx);
    } else {
      lifeguards.erase(idx);
    }

    prev = t;
  }

  cout << total - *min_element(alone.begin(), alone.end());
}
