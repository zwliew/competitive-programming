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

  // The minimum cost would be to match the shortest possible knight to the
  // smallest head.
  int n, m;
  while (cin >> n >> m && n && m) {
    vector<int> diameters(n);
    for (int &x : diameters) cin >> x;
    vector<int> heights(m);
    for (int &x : heights) cin >> x;
    sort(diameters.begin(), diameters.end());
    sort(heights.begin(), heights.end());
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m) {
      if (heights[j] >= diameters[i]) {
        ans += heights[j];
        ++i;
      }
      ++j;
    }

    if (i < n) {
      cout << "Loowater is doomed!\n";
    } else {
      cout << ans << '\n';
    }
  }
}
