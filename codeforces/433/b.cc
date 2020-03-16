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

  int n;
  cin >> n;
  vector<ll> v(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  vector<ll> u(v.begin(), v.end());
  sort(u.begin(), u.end());
  for (int i = 1; i < u.size(); ++i) {
    u[i] += u[i - 1];
  }
  for (int i = 1; i < v.size(); ++i) {
    v[i] += v[i - 1];
  }

  int m;
  cin >> m;
  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      cout << v[r] - v[l - 1] << '\n';
    } else {
      cout << u[r] - u[l - 1] << '\n';
    }
  }
}