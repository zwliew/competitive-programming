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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  ll cnt = 0;
  ll zero = 0;
  ll neg = 0, pos = 0;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    if (!a[i]) {
      zero++;
      ++cnt;
    } else if (a[i] < 0) {
      cnt += -1 - a[i];
      ++neg;
    } else {
      cnt += a[i] - 1;
      ++pos;
    }
  }
  if (neg & 1) {
    if (!zero) {
      cnt += 2;
    }
  }
  cout << cnt;
}