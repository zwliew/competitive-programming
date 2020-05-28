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

  // Calculate the total time needed.
  int s, t, n;
  cin >> s >> t >> n;
  int cur = s;
  vector<int> d(n + 1), b(n), c(n);
  for (int &i : d) cin >> i;
  for (int &i : b) cin >> i;
  for (int &i : c) cin >> i;
  for (int i = 0; i < n; ++i) {
    cur += d[i];
    cur += (c[i] - (cur % c[i])) % c[i];
    cur += b[i];
  }
  cur += d.back();
  cout << (cur <= t ? "yes" : "no");
}
