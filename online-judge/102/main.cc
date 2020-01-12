/*
ID: zhaowei10
TASK:
LANG: C++
*/
#include <algorithm>
#include <array>
#include <bitset>
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

#define pb push_back
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

typedef long long ll;
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
typedef vector<VII> VVII;
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

  int b[9];
  while (cin >> b[0]) {
    for (int i = 1; i < 9; ++i) cin >> b[i];

    int minc[3];
    int minm = INT_MAX;
    int c[3] = {0, 1, 2};  // b,g,c
    char d[3] = {'b', 'g', 'c'};
    do {
      int totm = 0;
      for (int i = 0; i < 9; ++i) {
        int col = c[i / 3];
        if (i % 3 != col) {
          totm += b[i];
        }
      }

      if (totm < minm) {
        minm = totm;
        copy(c, c + 3, minc);
      } else if (totm == minm) {
        for (int i = 0; i < 3; ++i) {
          if (d[c[i]] < d[minc[i]]) {
            copy(c, c + 3, minc);
            break;
          }
          if (d[c[i]] > d[minc[i]]) {
            break;
          }
        }
      }
    } while (next_permutation(c, c + 3));

    for (int i = 0; i < 3; ++i) {
      if (minc[i] == 0) {
        cout << 'B';
      } else if (minc[i] == 1) {
        cout << 'G';
      } else {
        cout << 'C';
      }
    }
    cout << ' ' << minm << '\n';
  }
}