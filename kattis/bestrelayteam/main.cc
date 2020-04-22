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
  vector<tuple<ld, ld, string>> v;
  for (int i = 0; i < n; ++i) {
    string a;
    ld b, c;
    cin >> a >> b >> c;
    v.emplace_back(c, b, a);
  }
  sort(v.begin(), v.end());
  int bestidx = n;
  ld besttime = 1e9;
  for (int i = 0; i < n; ++i) {
    ld curtime = get<1>(v[i]);
    for (int j = 0, cnt = 0; cnt < 3 && j < n; ++j) {
      if (j == i) continue;
      curtime += get<0>(v[j]);
      ++cnt;
    }
    if (curtime < besttime) {
      besttime = curtime;
      bestidx = i;
    }
  }
  cout << fixed << setprecision(9) << besttime << '\n';
  cout << get<2>(v[bestidx]) << '\n';
  for (int i = 0, cnt = 0; i < n && cnt < 3; ++i) {
    if (i == bestidx) continue;
    cout << get<2>(v[i]) << '\n';
    ++cnt;
  }
}
