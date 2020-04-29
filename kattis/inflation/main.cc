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

  // Since we can only fill a balloon with at most 1 canister, match the
  // smallest canister with the smallest balloon
  int n;
  cin >> n;
  vector<int> canisters(n);
  for (int &x : canisters) cin >> x;
  sort(canisters.begin(), canisters.end());

  ld ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (canisters[i - 1] > i) {
      cout << "impossible";
      return 0;
    }
    ans = min(ans, canisters[i - 1] / (ld)i);
  }
  cout << ans;
}
