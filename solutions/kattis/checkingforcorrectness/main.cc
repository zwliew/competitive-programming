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

const int mod = 1e9;
ll modpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string x, y, z;
  while (cin >> x >> y >> z) {
    ll xi = stoll(x);
    ll zi = stoll(z);
    xi %= mod;
    zi %= mod;
    if (y == "+") {
      cout << (xi + zi) % 10000;
    } else if (y == "*") {
      cout << (xi * zi) % 10000;
    } else {
      cout << modpow(xi, zi) % 10000;
    }
    cout << '\n';
  }
}
