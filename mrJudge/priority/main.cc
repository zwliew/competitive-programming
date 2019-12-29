// #include <bits/stdc++.h>
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define FOR(i, j, k, l) for (s32 i = j; i < k; i += l)
#define REP(i, j) FOR(i, 0, j, 1)
#define ALL(x) x.begin(), x.end()
#define MEAN(a, b) min(a, b) + (abs(b - a) / 2)
#define DIGITS(x) floor(log10(x)) + 1
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

int main() {
  // Don't collapse the block
  FASTIO();

  set<s64> s;
  PQPLL mod, dig, rev;
  s32 n;
  cin >> n;
  while (n--) {
    s64 x;
    cin >> x;
    mod.emplace(x % 13371337, x);

    s64 a = x, b = 0, c = 0;
    while (a > 0) {
      b += a % 10;
      c = c * 10 + a % 10;
      a /= 10;
    }
    dig.emplace(b, x);
    rev.emplace(c, x);
  }

  cin >> n;
  while (n--) {
    s64 x;
    cin >> x;
    PLLLL y;
    if (x == 1) {
      while (s.find((y = mod.top()).second) != s.end()) {
        mod.pop();
      }
    } else if (x == 2) {
      while (s.find((y = dig.top()).second) != s.end()) {
        dig.pop();
      }
    } else {
      while (s.find((y = rev.top()).second) != s.end()) {
        rev.pop();
      }
    }
    s.emplace(y.second);
    cout << y.second << '\n';
  }
}