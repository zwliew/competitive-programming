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

  int n;
  cin >> n;
  multiset<pair<int, int>> bst;
  while (n--) {
    string s;
    cin >> s;
    if (s == "add") {
      int e, g;
      cin >> e >> g;
      bst.emplace(e, g);
    } else {
      int x;
      cin >> x;
      ll tot = 0;
      while (bst.size()) {
        auto it = bst.upper_bound(make_pair(x, 1e9));
        if (it == bst.begin()) {
          break;
        }
        --it;
        auto &[e, g] = *it;
        x -= e;
        tot += g;
        bst.erase(it);
      }
      cout << tot << '\n';
    }
  }
}
