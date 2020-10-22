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

  int k, n;
  cin >> k >> n;

  priority_queue<pair<int, bool>> q;
  vector<tuple<int, int, bool>> moose;
  for (int i = 0; i < n + k - 2; ++i) {
    int year, strength;
    cin >> year >> strength;
    moose.emplace_back(year, strength, !i);
  }
  sort(moose.begin(), moose.end());

  for (int i = 0; i < n + k - 2;) {
    int j = i;
    while (j < n + k - 2 && get<0>(moose[j]) == get<0>(moose[i])) {
      q.emplace(get<1>(moose[j]), get<2>(moose[j]));
      ++j;
    }
    if (q.top().second) {
      cout << get<0>(moose[i]);
      return 0;
    }
    q.pop();
    i = j;
  }
  cout << "unknown";
}
