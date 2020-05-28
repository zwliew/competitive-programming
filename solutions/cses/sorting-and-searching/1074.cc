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

  // Simply take the difference between all the lengths and the length of the
  // median stick.
  int n;
  cin >> n;
  vector<int> x(n);
  for (int& i : x) cin >> i;
  sort(x.begin(), x.end());
  int target = x[x.size() / 2];
  ll ans = 0;
  for (int i : x) {
    ans += abs(i - target);
  }
  cout << ans;
}
