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

  // Number of ways to place without attacking = number of ways to place in
  // total - number of ways to place with attacking
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << (ll)i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << '\n';
  }
}
