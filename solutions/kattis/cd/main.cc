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

  int a, b;
  while (cin >> a >> b && a && b) {
    unordered_set<int> has;
    for (int i = 0; i < a; ++i) {
      int x;
      cin >> x;
      has.emplace(x);
    }
    int ans = 0;
    for (int i = 0; i < b; ++i) {
      int x;
      cin >> x;
      if (has.count(x)) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
}
