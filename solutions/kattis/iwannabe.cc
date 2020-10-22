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
  vector<pair<int64_t, int>> attack(n), defence(n), health(n);
  for (int i = 0; i < n; ++i) {
    int64_t a, d, h;
    cin >> a >> d >> h;
    attack[i] = {a, i};
    defence[i] = {d, i};
    health[i] = {h, i};
  }
  nth_element(attack.begin(), attack.begin() + k - 1, attack.end(),
              greater<pair<int64_t, int>>());
  nth_element(defence.begin(), defence.begin() + k - 1, defence.end(),
              greater<pair<int64_t, int>>());
  nth_element(health.begin(), health.begin() + k - 1, health.end(),
              greater<pair<int64_t, int>>());

  debug(attack, defence, health);

  int count = 0;
  vector<bool> used(n);
  for (int i = 0; i < k; ++i) {
    count += !used[attack[i].second];
    used[attack[i].second] = true;
    count += !used[defence[i].second];
    used[defence[i].second] = true;
    count += !used[health[i].second];
    used[health[i].second] = true;
  }
  cout << count;
}
