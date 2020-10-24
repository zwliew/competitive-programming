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

  string s;
  map<string, bool> indices, files;
  unordered_map<string, vector<string>> dupFiles;
  while (getline(cin, s) && s != "") {
    indices[s] = false;
  }
  while (getline(cin, s)) {
    int idx;
    int cnt = 0;
    for (idx = s.size() - 1; idx >= 0; --idx) {
      if (s[idx] == '_') {
        ++cnt;
      }
      if (cnt == 2)
        break;
    }
    string name = s.substr(0, idx);
    files[name] = false;
    if (indices.count(name)) {
      indices[name] = true;
      files[name] = true;
    }
    dupFiles[name].push_back(s);
  }

  bool mismatched = false;
  for (auto& [k, v] : files) {
    if (!v) {
      sort(dupFiles[k].begin(), dupFiles[k].end());
      for (auto& x : dupFiles[k]) {
        cout << "F " << x << "\n";
      }
      mismatched = true;
    }
  }

  for (auto& [k, v] : indices) {
    if (!v) {
      mismatched = true;
      cout << "I " << k << "\n";
    }
  }

  if (!mismatched) {
    cout << "No mismatches.";
  }
}
