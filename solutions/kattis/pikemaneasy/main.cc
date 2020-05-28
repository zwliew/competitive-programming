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

  int n, t, a, b, c, t0;
  cin >> n >> t >> a >> b >> c >> t0;
  vector<ll> v(n);
  v[0] = t0;
  for (int i = 1; i < n; ++i) {
    v[i] = ((a * v[i - 1] + b) % c) + 1;
  }
  sort(v.begin(), v.end());

  ll penalty = 0, i = 0, origt = t;
  while (i < n && t >= v[i]) {
    t -= v[i++];
    penalty += (origt - t);
    penalty %= 1000000007;
  }
  cout << i << ' ' << penalty;
}
