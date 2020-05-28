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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n, m, l;
    cin >> n >> m >> l;
    cout << "Case " << ti << '\n';
    vector<pair<int, string>> costs;
    for (int i = 0; i < l; ++i) {
      string x;
      cin >> x;
      int colon = x.find_first_of(':');
      int comma = x.find_first_of(',');

      string name(x.begin(), x.begin() + colon);
      int a = stoi(string(x.begin() + colon + 1, x.begin() + comma));
      int b = stoi(string(x.begin() + comma + 1, x.end()));

      int cur = n;
      int cost = 0;
      while (cur / 2 >= m && b < a * (cur - cur / 2)) {
        cur /= 2;
        cost += b;
      }
      if (cur > m) {
        cost += a * (cur - m);
      }

      costs.emplace_back(cost, name);
    }

    sort(costs.begin(), costs.end());

    for (auto &[cost, name] : costs) {
      cout << name << ' ' << cost << '\n';
    }
  }
}
