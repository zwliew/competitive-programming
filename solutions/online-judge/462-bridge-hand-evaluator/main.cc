/*
ID: zhaowei10
TASK: test
LANG: C++
*/
// #include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define MOD 1000000007
#define FOR(i, j, k, l) for (s32 i = j; i < k; i += l)
#define RFOR(i, j, k, l) for (s32 i = j; i >= k; i -= l)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(x) x.begin(), x.end()
#define MEAN(a, b) min(a, b) + (abs(b - a) >> 1)
#define FASTIO()    \
  cin.tie(nullptr); \
  ios::sync_with_stdio(false);

typedef int64_t s64;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint32_t u32;
typedef float f32;
typedef double f64;
typedef pair<s32, s32> II;
typedef pair<s64, s64> LL;
typedef vector<s32> VI;
typedef vector<II> VII;
typedef priority_queue<s32> PQI;
typedef priority_queue<s32, VI, greater<s32>> PQIA;
typedef priority_queue<s64> PQL;
typedef priority_queue<II> PQII;
typedef priority_queue<II, VII, greater<II>> PQIIA;
typedef priority_queue<LL> PQLL;
typedef unordered_set<s32> USI;
typedef unordered_set<s64> USL;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

int main() {
  // Don't collapse the block
  // FASTIO();

  vector<string> v(13);
  while (1) {
    s32 pt = 0, ptnt = 0;
    s32 c[4] = {0};
    s32 r[4][5] = {0};
    bool s[4] = {0};
    unordered_map<char, s32> sm = {{'S', 0}, {'H', 1}, {'D', 2}, {'C', 3}};
    unordered_map<s32, char> smr = {{0, 'S'}, {1, 'H'}, {2, 'D'}, {3, 'C'}};
    unordered_map<char, s32> rm = {{'A', 4}, {'K', 3}, {'Q', 2}, {'J', 1}};
    REP(i, v.size()) {
      if (!(cin >> v[i])) {
        return 0;
      }
      char rank = v[i][0];
      char suit = v[i][1];
      if (rm.find(rank) != rm.end()) {
        pt += rm[rank];
        ++r[sm[suit]][rm[rank]];
      }
      ++c[sm[suit]];
    }
    REP(i, 4) {
      pt -= r[i][3] * (c[i] == 1 ? 1 : 0);
      pt -= r[i][2] * (c[i] >= 1 && c[i] <= 2 ? 1 : 0);
      pt -= r[i][1] * (c[i] >= 1 && c[i] <= 3 ? 1 : 0);

      s[i] = r[i][4] || (r[i][3] && c[i] > 1) || (r[i][2] && c[i] > 2);
    }

    ptnt = pt;
    REP(i, 4) {
      ptnt += c[i] == 2;
      ptnt += (c[i] == 1 || !c[i]) << 1;
    }

    if (ptnt < 14) {
      cout << "PASS\n";
    } else if (pt >= 16 && all_of(s, s + 4, [](bool c) { return c; })) {
      cout << "BID NO-TRUMP\n";
    } else {
      cout << "BID " << smr[max_element(c, c + 4) - c] << '\n';
    }
  }
}