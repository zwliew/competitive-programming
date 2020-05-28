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

  // Stable sort using a custom comparator on the given attributes
  string x;
  vector<string> attrs;
  while (cin >> x) {
    bool isint = 1;
    for (int i = 0; i < x.size(); ++i) {
      if (!isdigit(x[i])) {
        isint = 0;
        break;
      }
    }
    if (isint) break;
    attrs.emplace_back(x);
  }

  int n = stoi(x);
  vector<vector<string>> songs(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < attrs.size(); ++j) {
      string x;
      cin >> x;
      songs[i].emplace_back(x);
    }
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    int idx;
    for (int j = 0; j < attrs.size(); ++j) {
      if (attrs[j] == x) {
        idx = j;
      }
      cout << attrs[j] << ' ';
    }
    cout << '\n';

    stable_sort(songs.begin(), songs.end(),
                [&](auto &lhs, auto &rhs) { return lhs[idx] < rhs[idx]; });

    for (auto &x : songs) {
      for (auto &y : x) {
        cout << y << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }
}
