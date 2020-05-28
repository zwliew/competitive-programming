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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int p, n;
  cin >> p >> n;
  int ans = 0;
  unordered_set<string> seen;
  while (n--) {
    string x;
    cin >> x;
    if (!seen.count(x)) {
      seen.emplace(x);
      --p;
    }
    ++ans;
    if (!p) {
      cout << ans;
      return 0;
    }
  }
  cout << "paradox avoided";
}
