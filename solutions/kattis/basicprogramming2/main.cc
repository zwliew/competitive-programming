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

  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  sort(v.begin(), v.end());
  if (t == 1) {
    int lo = 0;
    int hi = v.size() - 1;
    while (lo < hi) {
      int sum = v[lo] + v[hi];
      if (sum == 7777) {
        cout << "Yes";
        return 0;
      } else if (sum > 7777) {
        --hi;
      } else {
        ++lo;
      }
    }
    cout << "No";
  } else if (t == 2) {
    int prev = -1;
    for (int x : v) {
      if (x == prev) {
        cout << "Contains duplicate";
        return 0;
      }
      prev = x;
    }
    cout << "Unique";
  } else if (t == 3) {
    int prev = -1;
    int cnt = 0;
    for (int x : v) {
      if (x == prev) {
        ++cnt;
      } else {
        cnt = 1;
        prev = x;
      }
      if (cnt * 2 > v.size()) {
        cout << prev;
        return 0;
      }
    }
    cout << -1;
  } else if (t == 4) {
    if (v.size() % 2) {
      cout << v[v.size() / 2];
    } else {
      cout << v[v.size() / 2 - 1] << ' ' << v[v.size() / 2];
    }
  } else {
    for (int i : v) {
      if (i >= 100 && i <= 999) {
        cout << i << ' ';
      }
    }
  }
}
