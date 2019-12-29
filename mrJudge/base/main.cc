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

inline long long pw(long long i, long long p) {
  return !p ? 1 : p >> 1 ? pw(i * i, p >> 1) * (p % 2 ? i : 1) : i;
}

int main() {
  // Don't collapse the block
  FASTIO();

  string x;
  s64 a, b;
  cin >> x >> a >> b;

  if (a == b || x == "0") {
    cout << x;
    return 0;
  }

  s64 b10 = 0;
  if (a == 10) {
    b10 = stoi(x);
  } else {
    REP(i, x.size()) {
      s64 c;
      if (isdigit(x[i])) {
        c = x[i] - '0';
      } else {
        c = x[i] - 'A' + 10;
      }
      b10 += c * pw(a, x.size() - 1 - i);
    }

    if (b == 10) {
      cout << b10;
      return 0;
    }
  }

  string r;
  while (b10) {
    s64 c;
    c = b10 % b;
    if (c >= 10) {
      c += 'A' - 10;
    } else {
      c += '0';
    }
    // cout << b10 << ' ' << b10 / b << ' ' << c << '\n';
    r.push_back(c);
    b10 /= b;
  }
  reverse(r.begin(), r.end());

  cout << r;
}