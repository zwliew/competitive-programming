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

  // Use a binary search tree to support efficient searches and deletions.
  int n, m;
  cin >> n >> m;
  multiset<int> h;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    h.emplace(x);
  }
  while (m--) {
    int x;
    cin >> x;
    auto it = h.upper_bound(x);
    if (it == h.begin()) {
      cout << "-1\n";
    } else {
      cout << *prev(it) << '\n';
      h.erase(prev(it));
    }
  }
}
