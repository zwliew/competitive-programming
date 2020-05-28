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

  // Greedily pair the next lightest child with the next heaviest child
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int &i : c) cin >> i;
  sort(c.begin(), c.end());
  int i = 0, j = n - 1;
  int ans = 0;
  while (i < j) {
    if (c[i] + c[j] <= x) {
      ++ans;
      ++i;
      --j;
    } else {
      ++ans;
      --j;
    }
  }
  if (i == j) {
    ++ans;
  }
  cout << ans;
}
