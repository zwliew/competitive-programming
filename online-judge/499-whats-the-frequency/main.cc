/*
ID: zhaowei10
TASK: test
LANG: C++
*/
// #include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
typedef vector<char> VC;
typedef priority_queue<s32> PQI;
typedef priority_queue<s32, VI, greater<s32>> PQIA;
typedef priority_queue<s64> PQL;
typedef priority_queue<II> PQII;
typedef priority_queue<II, VII, greater<II>> PQIIA;
typedef priority_queue<LL> PQLL;
typedef unordered_set<s32> USI;
typedef unordered_set<s64> USL;
typedef set<II> SII;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

int main() {
  FASTIO();

  string s;
  while (getline(cin, s)) {
    if (s.empty()) {
      break;
    }

    map<char, s32> m;
    s32 cmax = 0;
    VC vmax;
    REP(i, s.size()) {
      if (!isalpha(s[i])) {
        continue;
      }
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = 0;
      }
      ++m[s[i]];
      if (m[s[i]] > cmax) {
        cmax = m[s[i]];
        vmax = VC();
        vmax.emplace_back(s[i]);
      } else if (m[s[i]] == cmax) {
        vmax.emplace_back(s[i]);
      }
    }

    sort(vmax.begin(), vmax.end());

    for (char i : vmax) {
      cout << i;
    }
    cout << ' ' << cmax << '\n';
  }
}