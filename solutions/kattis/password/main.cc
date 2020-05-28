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

  int n;
  cin >> n;

  ld ans = 0;
  vector<ld> possibilities(n);
  for (ld &x : possibilities) {
    string _;
    cin >> _ >> x;
  }
  sort(possibilities.rbegin(), possibilities.rend());
  for (int i = 1; i <= n; ++i) {
    ans += i * possibilities[i - 1];
  }
  cout << fixed << setprecision(4) << ans;
}
