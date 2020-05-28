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

  // Sort the socks, and check if the current sock is fits into the previous
  // washing machine.
  int s, c, k;
  cin >> s >> c >> k;
  vector<int> socks(s);
  for (int &x : socks) cin >> x;
  sort(socks.begin(), socks.end());
  int end = -1e9;
  int cnt = 0;
  int ans = 0;
  for (int x : socks) {
    if (cnt == c || x > end) {
      ++ans;
      cnt = 0;
      end = x + k;
    }
    ++cnt;
  }
  cout << ans;
}
