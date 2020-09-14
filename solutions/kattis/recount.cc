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

  // Count the frequencies and sort
  string s;
  unordered_map<string, int> cnt;
  while (getline(cin, s) && s != "***") {
    ++cnt[s];
  }

  vector<pair<int, string>> sorted;
  for (auto& [k, v] : cnt) {
    sorted.emplace_back(v, k);
  }
  sort(sorted.rbegin(), sorted.rend());

  if (sorted.size() == 1 || sorted[0].first > sorted[1].first) {
    cout << sorted[0].second;
  } else {
    cout << "Runoff!";
  }
}
