#include <algorithm>
#include <array>
#include <bitset>
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

ll solve(ll n, ll length, ll k) {
  ll hf = length >> 1;
  if (k <= hf) {
    return solve(n - 1, hf, k);
  }
  if (k == hf + 1) {
    return n;
  }
  if (k > hf + 1) {
    return solve(n - 1, hf, k - hf - 1);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  ll len = 1;
  for (ll i = 2; i <= n; ++i) {
    len = 2 * len + 1;
  }
  cout << solve(n, len, k);
}

// 1 - 1
// 2 - 1 2 1
// 3 - 1 2 1 3 1 2 1
// 4 - 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1

// n == 1 => 1
// n == n => 2 * f(n - 1) + 1
// n == 2 =>