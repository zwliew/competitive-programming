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

template <typename T>
inline vector<T> initSet(T size) {
  vector<T> p(size + 1);
  iota(p.begin(), p.end(), 0);
  return p;
}

template <typename T>
inline T findSet(vector<T> &p, T a) {
  return p[a] == a ? a : (p[a] = findSet(p, p[a]));
}

template <typename T>
inline bool isSameSet(vector<T> &p, T a, T b) {
  return findSet(p, a) == findSet(p, b);
}

template <typename T>
inline void unionSet(vector<T> &p, T a, T b) {
  p[findSet(p, a)] = findSet(p, b);
}

int main() {
  FASTIO();

  s32 n, m;
  cin >> n >> m;

  VI p(n + 1);
  REP(i, n) { cin >> p[i + 1]; }

  VI t = initSet(n);

  REP(i, m) {
    s32 a, b;
    cin >> a >> b;

    if (isSameSet(t, a, b)) {
      cout << -1 << '\n';
      continue;
    }

    s32 as = findSet(t, a);
    s32 bs = findSet(t, b);
    if (p[as] > p[bs]) {
      unionSet(t, b, a);
      cout << as << '\n';
    } else {
      unionSet(t, a, b);
      cout << bs << '\n';
    }
  }
}