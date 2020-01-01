/*
ID: zhaowei10
TASK:
LANG: C++
*/
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
typedef multiset<s32> MSI;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

template <typename T>
inline s32 ndigits(T x) {
  s32 r = 0;
  while (x) {
    x /= 10;
    ++r;
  }
  return r;
}

int main() {
  FASTIO();

  s32 n;
  while (cin >> n) {
    s32 m;
    cin >> m;
    string z;
    cin >> z;
    char a = z[0], b = z[1], c = z[2];

    s32 cnt = 0;
    array<s32, 128> k;
    fill(k.begin(), k.end(), -1);
    unordered_map<char, VC> e;
    REP(i, m) {
      string z;
      cin >> z;
      char x = z[0], y = z[1];
      if (k[x] == -1) {
        k[x] = cnt++;
      }
      if (k[y] == -1) {
        k[y] = cnt++;
      }
      if (e.find(x) == e.end()) {
        e[x] = VC();
      }
      if (e.find(y) == e.end()) {
        e[y] = VC();
      }
      e[x].emplace_back(y);
      e[y].emplace_back(x);
    }

    USI s;
    PQIIA q;
    q.emplace(0, a);
    q.emplace(0, b);
    q.emplace(0, c);
    s32 tm = 0;
    while (!q.empty()) {
      II x = q.top();
      q.pop();
      if (s.find(x.second) != s.end()) continue;
      s.emplace(x.second);
      amax(tm, x.first);
      for (char n : e[x.second]) {
        s32 na = 0;
        for (char nn : e[n]) {
          if (s.find(nn) != s.end()) {
            if (++na >= 3) {
              q.emplace(x.first + 1, n);
            }
          }
        }
      }
    }

    if (s.size() < n) {
      cout << "THIS BRAIN NEVER WAKES UP\n";
      continue;
    }
    cout << "WAKE UP IN, " << tm << ", YEARS\n";
  }
}