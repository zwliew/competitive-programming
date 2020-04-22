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

  // Simply add the number if it doesn't satisfy the conditions.
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 3 && i % 5) {
      ans += i;
    }
  }
  cout << ans;
}
