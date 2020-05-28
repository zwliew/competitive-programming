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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Point update range queries on a dynamic array.
  // Queries involve the first array prefix sum not smaller than a certain
  // value.
  // Use a standard binary indexed tree.
  int n;
  cin >> n;
  vector<int> t(n + 1);
  unordered_map<int, int> hm;
  auto add = [&](int idx, int x) {
    for (++idx; idx <= n; idx += idx & -idx) {
      t[idx] += x;
    }
  };
  auto query = [&](int idx) {
    int res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += t[idx];
    }
    return res;
  };
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    hm[i] = x;
    add(i, 1);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (query(mid) >= x) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    assert(ans != -1);
    add(ans, -1);
    cout << hm[ans] << ' ';
  }
}
