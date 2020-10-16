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

  string s;
  getline(cin, s);
  int n;
  cin >> n;
  getline(cin, s);
  vector<vector<string>> choices(n);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    istringstream ss(s);
    string cur;
    while (ss >> s) {
      if (cur.size())
        cur += ' ';
      cur += s;
      if (s.back() == ',') {
        cur.pop_back();
        choices[i].push_back(cur);
        cur = "";
      }
    }
    if (cur.size())
      choices[i].push_back(cur);
  }

  vector<int> bestChoices;
  int bestChanges = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int maxChanges = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      int curChanges = 0;
      for (int k = 0; k < choices[i].size(); ++k) {
        if (choices[i][k] != choices[j][k]) {
          ++curChanges;
        }
      }
      maxChanges = max(maxChanges, curChanges);
    }
    if (maxChanges < bestChanges) {
      bestChanges = maxChanges;
      bestChoices = {i};
    } else if (maxChanges == bestChanges) {
      bestChoices.push_back(i);
    }
  }

  for (int idx : bestChoices) {
    for (int i = 0; i < choices[idx].size(); ++i) {
      if (i) {
        cout << ", ";
      }
      cout << choices[idx][i];
    }
    cout << "\n";
  }
}
