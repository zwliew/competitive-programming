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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Simulate the process
  vector<int> m(26);
  for (int i = 1; i < 11; ++i)
    m[i] = 5;
  for (int i = 11; i < 16; ++i)
    m[i] = 4;
  for (int i = 16; i < 21; ++i)
    m[i] = 3;
  for (int i = 21; i < 26; ++i)
    m[i] = 2;

  string s;
  cin >> s;
  int rank = 25;
  int stars = 0;
  int consec = 0;
  for (char c : s) {
    if (c == 'W') {
      ++stars;
      ++consec;
      if (rank >= 6 && rank <= 25 && consec >= 3) {
        ++stars;
      }
      if (rank && stars > m[rank]) {
        stars -= m[rank];
        --rank;
      }
    } else {
      consec = 0;
      if (rank >= 1 && rank <= 20) {
        --stars;
      }
      if (rank >= 20) {
        stars = max(stars, 0);
      }
      if (stars < 0 && rank >= 1) {
        ++rank;
        stars = m[rank] - 1;
      }
    }
  }

  if (!rank)
    cout << "Legend";
  else
    cout << rank;
}
