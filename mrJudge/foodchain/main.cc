// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define FOR(i, j, k, l) for (s32 i = j; i < k; i += l)
#define RFOR(i, j, k, l) for (s32 i = j; i >= k; i -= l)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(x) x.begin(), x.end()
#define MEAN(a, b) min(a, b) + (abs(b - a) / 2)
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
typedef priority_queue<pair<s32, s32>> PQPI;
typedef priority_queue<pair<s64, s64>> PQPLL;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T>
inline T ndigits(T x) {
  T y;
  while (x) {
    x /= 10;
    ++y;
  }
  return y;
}

int main() {
  // Don't collapse the block
  FASTIO();

  u64 x;
  cin >> x;
  for (u64 i = 1; i < 5; ++i) {
    u64 a = 0;
    u64 y;
    cin >> y;
    for (y %= 1000000009; x; x >>= 1) {
      a += (x & 1) * y;
      a %= 1000000009;
      y <<= 1;
      y %= 1000000009;
    }
    x = a;
  }
  cout << x;
}