#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  // Find the smallest index `i` such that every song at or before `i` is seen
  // `m` times in total over all the arrays.
  // Efficiently do this with a hash table.
  int m, s;
  cin >> m >> s;
  vector<vector<int>> v(m, vector<int>(s));
  for (int i = 0; i < m; ++i) {
    for (int &x : v[i]) {
      cin >> x;
    }
  }

  unordered_map<int, int> ht;
  int i;
  bool ok = 0;
  for (i = 0; i < s; ++i) {
    for (int j = 0; j < m; ++j) {
      ++ht[v[j][i]];
      if (ht[v[j][i]] == m) {
        ht.erase(v[j][i]);
      }
    }

    if (!ht.size()) {
      break;
    }
  }

  vector<int> ans;
  for (int j = 0; j <= i; ++j) {
    ans.emplace_back(v[0][j]);
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << ' ';
  }
}
