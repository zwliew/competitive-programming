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

  int c, p;
  cin >> c >> p;
  vector<vector<int>> parties(p, vector<int>(c));
  vector<int> votes(p);
  int totalVotes = 0;
  for (int i = 0; i < p; ++i) {
    cin >> votes[i];
    totalVotes += votes[i];
    for (int j = 0; j < c; ++j) {
      cin >> parties[i][j];
      --parties[i][j];
    }
    reverse(parties[i].begin(), parties[i].end());
  }

  vector<bool> eliminated(c);
  while (true) {
    vector<int> counts(c);
    for (int i = 0; i < p; ++i) {
      while (parties[i].size() && eliminated[parties[i].back()]) {
        parties[i].pop_back();
      }
      if (parties[i].size()) {
        counts[parties[i].back()] += votes[i];
      }
    }

    int mnIdx = -1, mxIdx = -1;
    for (int i = 0; i < c; ++i) {
      if (eliminated[i])
        continue;
      if (mnIdx == -1 || counts[i] < counts[mnIdx]) {
        mnIdx = i;
      }
      if (mxIdx == -1 || counts[i] > counts[mxIdx]) {
        mxIdx = i;
      }
    }

    if (counts[mxIdx] * 2 > totalVotes) {
      cout << mxIdx + 1;
      return 0;
    }
    eliminated[mnIdx] = true;
  }
}
