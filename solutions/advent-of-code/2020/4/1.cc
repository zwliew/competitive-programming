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
#include <random>
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

  vector<string> required = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

  int cnt = 0;
  string s;
  while (getline(cin, s)) {
    string cur = s;
    while (getline(cin, s) && s != "") {
      cur += " ";
      cur += s;
    }
    if (!cnt)
      debug(cnt, cur);

    vector<bool> found(required.size());
    istringstream ss(cur);
    while (ss >> s) {
      if (!cnt) {
        debug(s);
      }
      string k = s.substr(0, 3);
      int idx = find(required.begin(), required.end(), k) - required.begin();
      if (idx < required.size())
        found[idx] = true;
    }

    if (accumulate(found.begin(), found.end(), 0) == found.size()) {
      ++cnt;
    }
  }
  cout << cnt;
}
