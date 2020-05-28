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

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define MOD 1000000007
#define NDIG(x) floor(log10(x)) + 1
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
typedef long double f80;
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

vector<vector<vector<int>>> mem(205,
                                vector<vector<int>>(205, vector<int>(3, -1)));

int dp(int n, int k, int prev, vector<pair<int, int>> &v) {
  if (n == 0) {
    if (k > 1) {
      return -1e8;
    }

    if (k == 1) {
      if (prev == 0) {
        return max(v[0].first, v[0].second);
      }

      if (prev == 1) {
        return v[0].first;
      }

      return v[0].second;
    }

    return v[0].first + v[0].second;
  }

  if (mem[n][k][prev] != -1) {
    return mem[n][k][prev];
  }

  mem[n][k][prev] = v[n].first + v[n].second + dp(n - 1, k, 0, v);
  if (k > 0) {
    if (prev == 1 || prev == 0) {
      mem[n][k][prev] =
          max(mem[n][k][prev], v[n].first + dp(n - 1, k - 1, 1, v));
    }

    if (prev == 2 || prev == 0) {
      mem[n][k][prev] =
          max(mem[n][k][prev], v[n].second + dp(n - 1, k - 1, 2, v));
    }
  }
  return mem[n][k][prev];
}

int main() {
  FASTIO();

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.emplace_back(x, y);
  }

  cout << dp(n - 1, k, 0, v);
}