#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Try every possible pair of marks
  // Pretty straightforward implementation problem
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    int x;
    vector<int> a;
    while (ss >> x) {
      a.push_back(x);
    }
    sort(a.begin(), a.end());

    bool ruler = true;
    vector<bool> seen(a.back() + 1);
    for (int i = 0; i < a.size() && ruler; ++i) {
      for (int j = i + 1; j < a.size(); ++j) {
        if (seen[a[j] - a[i]]) {
          ruler = false;
          break;
        }
        seen[a[j] - a[i]] = true;
      }
    }

    if (!ruler) {
      cout << "not a ruler\n";
      continue;
    }

    vector<int> missing;
    for (int i = 1; i <= a.back(); ++i) {
      if (!seen[i]) {
        missing.push_back(i);
      }
    }

    if (missing.empty()) {
      cout << "perfect\n";
    } else {
      cout << "missing ";
      for (int x : missing) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
}
