#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    cin >> n;
    vector<string> names(n);
    string s;
    getline(cin, s);
    for (auto& x : names) {
      getline(cin, x);
    }
    sort(names.begin(), names.end());
    debug(names);

    int bestIdx = -1;
    int bestSz = 0;
    for (int i = 0; i < n; ++i) {
      auto us = unordered_set<char>(names[i].begin(), names[i].end());
      int sz = us.size() + (us.count(' ') ? -1 : 0);
      if (sz > bestSz) {
        bestSz = sz;
        bestIdx = i;
      }
    }

    cout << "Case #" << ti << ": " << names[bestIdx] << "\n";
  }
}
