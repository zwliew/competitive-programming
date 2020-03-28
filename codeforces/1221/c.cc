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

  int q;
  cin >> q;
  while (q--) {
    int c, m, x;
    cin >> c >> m >> x;
    if (c > m) {
      x += c - m;
      c = m;
    } else {
      x += m - c;
      m = c;
    }
    int ans = min({c, m, x});
    c -= ans;
    m -= ans;
    cout << ans + (c + m) / 3 << '\n';
  }
}