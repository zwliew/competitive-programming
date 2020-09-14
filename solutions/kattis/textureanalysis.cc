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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "berries"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Iterate through the string and check if the distance between every pair of
  // consecutive stars is the same.
  string s;
  int i = 1;
  while (cin >> s && s != "END") {
    int prev = 0;
    int d = -1;
    bool ok = true;
    for (int j = 1; j < s.size(); ++j) {
      if (s[j] == '*') {
        int cd = j - prev;
        if (d != -1 && cd != d) {
          ok = false;
          break;
        }
        d = cd;
        prev = j;
      }
    }

    cout << i << ' ';
    if (!ok) {
      cout << "NOT ";
    }
    cout << "EVEN\n";
    ++i;
  }
}
