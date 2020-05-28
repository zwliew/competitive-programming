// #include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
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
typedef pair<s64, s64> LLLL;
typedef vector<s32> VI;
typedef vector<II> VII;
typedef priority_queue<s32> PQI;
typedef priority_queue<s64> PQLL;
typedef priority_queue<II> PQII;
typedef priority_queue<II, VII, greater<II>> PQIIA;
typedef priority_queue<LLLL> PQLLLL;
typedef unordered_set<s32> USI;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

int n, m, q, vn[1000000];
inline void read(int &x) {
  x = 0;
  char ch = getchar_unlocked();
  while (ch < '0' || ch > '9') ch = getchar_unlocked();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar_unlocked();
  }
}

int main() {
  // Don't collapse the block
  FASTIO();

  read(n);
  read(m);
  read(q);

  PQIIA j;
  REP(i, n) {
    read(vn[i]);
    if (vn[i]) {
      j.emplace(0, i);
    }
    vn[i] = -1;
  }

  unordered_map<s32, VI> f;
  s32 x, y;
  REP(i, m) {
    read(x);
    read(y);
    --x;
    --y;
    if (f.find(x) == f.end()) {
      f[x] = VI();
    }
    if (f.find(y) == f.end()) {
      f[y] = VI();
    }
    f[x].emplace_back(y);
    f[y].emplace_back(x);
  }

  REP(i, q) {
    read(x);
    read(x);
    read(y);
    j.emplace(y, x - 1);
  }

  while (!j.empty()) {
    II x = j.top();
    j.pop();
    if (vn[x.second] > -1) {
      continue;
    }

    vn[x.second] = x.first;

    REP(i, f[x.second].size()) { j.emplace(x.first + 1, f[x.second][i]); }
  }

  REP(i, n) { cout << vn[i] << ' '; }
}