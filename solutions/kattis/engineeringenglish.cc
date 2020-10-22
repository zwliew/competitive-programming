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

  auto lower = [](string s) {
    string res;
    for (char c : s) {
      res += tolower(c);
    }
    return res;
  };

  unordered_set<string> seen;
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    while (ss >> s) {
      auto lowered = lower(s);
      if (seen.count(lowered)) {
        cout << ".";
      } else {
        cout << s;
      }
      cout << " ";
      seen.insert(lowered);
    }
    cout << "\n";
  }
}
