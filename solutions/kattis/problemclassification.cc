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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

  int n;
  cin >> n;
  unordered_map<string, vector<string>> related;
  unordered_map<string, int> occurrences;
  while (n--) {
    string cat;
    int m;
    cin >> cat >> m;
    occurrences[cat] = 0;
    while (m--) {
      string w;
      cin >> w;
      related[w].push_back(cat);
    }
  }

  string s;
  while (cin >> s) {
    for (auto& cat : related[s]) {
      occurrences[cat]++;
    }
  }

  int maxCnt = 0;
  vector<string> ans;
  for (auto& [k, v] : occurrences) {
    maxCnt = max(maxCnt, v);
  }
  for (auto& [k, v] : occurrences) {
    if (v == maxCnt) {
      ans.push_back(k);
    }
  }
  sort(ans.begin(), ans.end());

  for (auto& x : ans) {
    cout << x << '\n';
  }
}
