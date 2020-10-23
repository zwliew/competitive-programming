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

  unordered_map<string, int> total;
  unordered_map<string, unordered_set<string>> seenBy;
  unordered_set<string> people;
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    istringstream ss(s);
    string name;
    ss >> name;
    while (ss >> s) {
      total[s]++;
      seenBy[s].insert(name);
    }
    people.insert(name);
  }

  int maxFreq = 0;
  for (auto& [k, v] : total) {
    maxFreq = max(maxFreq, v);
  }

  vector<pair<int, string>> ans;
  for (auto& [k, v] : seenBy) {
    if (v.size() == people.size()) {
      ans.emplace_back(-total[k], k);
    }
  }

  if (ans.empty()) {
    cout << "ALL CLEAR";
    return 0;
  }

  sort(ans.begin(), ans.end());
  for (auto& p : ans) {
    cout << p.second << "\n";
  }
}
