// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
typedef pair<s32, s32> PII;
typedef pair<s64, s64> PLLLL;
typedef vector<s32> VI;
typedef vector<PII> VPII;
typedef priority_queue<s32> PQI;
typedef priority_queue<s64> PQLL;
typedef priority_queue<PII> PQPII;
typedef priority_queue<PLLLL> PQPLLLL;
typedef unordered_set<s32> USI;

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
  FASTIO();

  s32 t;
  cin >> t;
  while (t--) {
    s32 ng, nm;
    cin >> ng >> nm;

    s32 gmax = 0, mmax = 0;
    REP(i, ng) {
      s32 g;
      cin >> g;
      amax(gmax, g);
    }
    REP(i, nm) {
      s32 m;
      cin >> m;
      amax(mmax, m);
    }

    if (gmax > mmax) {
      cout << "Godzilla\n";
      continue;
    } else if (gmax < mmax) {
      cout << "MechaGodzilla\n";
      continue;
    }

    if (ng >= nm) {
      cout << "Godzilla\n";
    } else {
      cout << "MechaGodzilla\n";
    }
  }
}