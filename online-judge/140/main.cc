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

  string s;
  while (cin >> s && s != "#") {
    unordered_set<char> seen;
    unordered_map<char, unordered_set<char>> adj;
    char curv = 0;
    for (char c : s) {
      if (c == ';') {
        curv = 0;
        continue;
      }

      if (c == ':') {
        continue;
      }

      if (!seen.count(c)) {
        seen.emplace(c);
      }

      if (!curv) {
        curv = c;
      } else {
        adj[curv].emplace(c);
        adj[c].emplace(curv);
      }
    }

    vector<char> v;
    for (char c : seen) {
      v.pb(c);
    }
    sort(v.begin(), v.end());

    int mindist = INT_MAX;
    vector<char> minv(v.size());
    do {
      int cdist = 0;
      for (int i = 0; i < v.size(); ++i) {
        int dist = 0;
        for (int j = 0; j < v.size(); ++j) {
          if (j == i) continue;
          if (!adj[v[i]].count(v[j])) continue;
          amax(dist, j - i);
        }
        amax(cdist, dist);
      }
      if (cdist < mindist) {
        mindist = cdist;
        copy(v.begin(), v.end(), minv.begin());
      } else if (cdist == mindist) {
        for (int i = 0; i < v.size(); ++i) {
          if (v[i] < minv[i]) {
            copy(v.begin(), v.end(), minv.begin());
            break;
          } else if (v[i] > minv[i]) {
            break;
          }
        }
      }
    } while (next_permutation(v.begin(), v.end()));

    for (char c : minv) {
      cout << c << ' ';
    }
    cout << "-> " << mindist << '\n';
  }
}