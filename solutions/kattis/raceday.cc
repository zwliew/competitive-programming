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

  unordered_map<string, int> splitIdx = {
      {"S1", 0},
      {"S2", 1},
      {"F", 2},
  };

  int n;
  while (cin >> n && n) {
    vector<tuple<string, string, string>> runners(n);
    for (auto& [firstName, lastName, bib] : runners) {
      cin >> firstName >> lastName >> bib;
    }
    sort(runners.begin(), runners.end(), [](auto& x, auto& y) {
      return tie(get<1>(x), get<0>(x)) < tie(get<1>(y), get<0>(y));
    });

    unordered_map<string, array<string, 3>> timings;
    unordered_map<string, array<int, 3>> ranks;
    array<vector<pair<string, string>>, 3> sorted;
    for (int i = 0; i < n * 3; ++i) {
      string bib, split, time;
      cin >> bib >> split >> time;
      timings[bib][splitIdx[split]] = time;
      sorted[splitIdx[split]].emplace_back(bib, time);
    }
    for (int i = 0; i < 3; ++i) {
      sort(sorted[i].begin(), sorted[i].end(),
           [](auto& x, auto& y) { return x.second < y.second; });
      int rank = 1;
      for (int j = 0; j < n; ++j) {
        if (j && sorted[i][j].second > sorted[i][j - 1].second) {
          rank = j + 1;
        }
        ranks[sorted[i][j].first][i] = rank;
      }
    }

    printf("%-20s%10s%10s%10s%10s%10s%10s%10s\n", "NAME", "BIB", "SPLIT1",
           "RANK", "SPLIT2", "RANK", "FINISH", "RANK");
    for (auto& [firstName, lastName, bib] : runners) {
      auto curTimings = timings[bib];
      auto curRanks = ranks[bib];
      printf("%-20s%10s%10s%10d%10s%10d%10s%10d\n",
             (lastName + ", " + firstName).c_str(), bib.c_str(),
             curTimings[0].c_str(), curRanks[0], curTimings[1].c_str(),
             curRanks[1], curTimings[2].c_str(), curRanks[2]);
    }
    printf("\n");
  }
}
