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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Find the minimum number of points needed such that every range has at least
  // 1 point. Solve greedily by sorting in ascending order of range endpoints.
  int n, m;
  cin >> n >> m;
  vector<ii> p(n);
  for (auto &[e, s] : p) {
    int d, r;
    cin >> d >> r;
    s = d - r;
    e = d + r;
  }
  sort(p.begin(), p.end());

  int prev = -1e9;
  int cnt = 0;
  for (auto &[e, s] : p) {
    if (prev < s || prev > e) {
      prev = e;
      ++cnt;
    }
  }
  cout << cnt;
}
