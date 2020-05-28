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

  int n;
  cin >> n;
  vector<pair<int, string>> a, b, c;
  for (int i = 0; i < n; ++i) {
    string name;
    int x, y, z;
    cin >> name >> x >> y >> z;
    a.emplace_back(x, name);
    b.emplace_back(y, name);
    c.emplace_back(z, name);
  }

  sort(a.begin(), a.end(), [&](auto &lhs, auto &rhs) {
    if (lhs.first != rhs.first) return lhs.first > rhs.first;
    return lhs.second < rhs.second;
  });
  sort(b.begin(), b.end(), [&](auto &lhs, auto &rhs) {
    if (lhs.first != rhs.first) return lhs.first > rhs.first;
    return lhs.second < rhs.second;
  });
  sort(c.begin(), c.end(), [&](auto &lhs, auto &rhs) {
    if (lhs.first != rhs.first) return lhs.first > rhs.first;
    return lhs.second < rhs.second;
  });

  unordered_set<string> used;
  int ai = 0, bi = 0, ci = 0;
  for (int i = 0; i < n / 3; ++i) {
    vector<string> names;

    while (used.count(a[ai].second)) {
      ++ai;
    }
    names.emplace_back(a[ai].second);
    used.emplace(a[ai].second);

    while (used.count(b[bi].second)) {
      ++bi;
    }
    names.emplace_back(b[bi].second);
    used.emplace(b[bi].second);

    while (used.count(c[ci].second)) {
      ++ci;
    }
    names.emplace_back(c[ci].second);
    used.emplace(c[ci].second);

    sort(names.begin(), names.end());
    for (string name : names) {
      cout << name << ' ';
    }
    cout << '\n';
  }
}
