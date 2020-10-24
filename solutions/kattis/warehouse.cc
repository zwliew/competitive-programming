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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    while (n--) {
      string s;
      int x;
      cin >> s >> x;
      cnt[s] += x;
    }

    cout << cnt.size() << '\n';
    vector<pair<int, string>> sorted;
    for (auto& [k, v] : cnt) {
      sorted.emplace_back(-v, k);
    }
    sort(sorted.begin(), sorted.end());
    for (auto& p : sorted) {
      cout << p.second << " " << -p.first << "\n";
    }
  }
}
