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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    v[i] -= x;
  }

  sort(v.begin(), v.end());

  ll cnt = 0;
  ll l = 0, r = n - 1;
  while (l < r) {
    if (v[r] + v[l] > 0) {
      // cout << l << ' ' << r << ' ' << cnt << '\n';
      cnt += r - l;
      --r;
    } else {
      // cout << "cannot " << r << ' ' << l << '\n';
      ++l;
    }
  }
  cout << cnt;
}
// 4 8 2 6 2
// 4 5 4 1 3
// 0 3 -2 5 -1
// -2 -1 0 3 5