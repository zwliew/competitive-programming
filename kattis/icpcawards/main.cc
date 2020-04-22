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

  unordered_set<string> seen;
  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    string a, b;
    cin >> a >> b;
    if (!seen.count(a)) {
      seen.emplace(a);
      cout << a << ' ' << b << '\n';
      ++cnt;
      if (cnt == 12) return 0;
    }
  }
}
