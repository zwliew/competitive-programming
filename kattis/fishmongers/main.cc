#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Pair the heaviest fish to the fishmonger that pays the most per kilo
  int n, m;
  cin >> n >> m;
  vector<int> weights(n);
  for (int &x : weights) cin >> x;
  vector<pair<int, int>> mongers(m);
  for (auto &[p, x] : mongers) cin >> x >> p;
  sort(mongers.rbegin(), mongers.rend());
  sort(weights.rbegin(), weights.rend());
  ll ans = 0;
  int j = 0;
  for (int i = 0, j = 0; i < n && j < m; ++i) {
    ans += (ll)weights[i] * mongers[j].first;
    if (mongers[j].second == 1) {
      ++j;
    } else {
      --mongers[j].second;
    }
  }
  cout << ans;
}
