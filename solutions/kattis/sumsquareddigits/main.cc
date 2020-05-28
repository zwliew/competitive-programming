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

  int p;
  cin >> p;
  while (p--) {
    int k, b, n;
    cin >> k >> b >> n;
    int ans = 0;
    while (n) {
      ans += (n % b) * (n % b);
      n /= b;
    }
    cout << k << ' ' << ans << '\n';
  }
}
