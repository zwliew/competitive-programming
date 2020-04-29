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

  // Put each of the largest 3 books into a group
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int &x : prices) cin >> x;
  sort(prices.rbegin(), prices.rend());
  int ans = 0;
  for (int i = 0; i < n - n % 3; i += 3) {
    ans += prices[i] + prices[i + 1];
  }
  for (int i = n - n % 3; i < n; ++i) {
    ans += prices[i];
  }
  cout << ans;
}
