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
  vector<ll> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<vector<ll>> d(1000001);
  for (int i = 0; i < n; ++i) {
    int x = i - b[i];
    d[x + 500000].push_back(i);
  }

  ll t = 0;
  for (int i = 0; i < d.size(); ++i) {
    ll c = 0;
    for (int j = 0; j < d[i].size(); ++j) {
      c += b[d[i][j]];
    }
    t = max(t, c);
  }
  cout << t;
}