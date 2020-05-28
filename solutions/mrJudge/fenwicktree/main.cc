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
inline s32 ndigits(T x, T b) {
  s32 r = 0;
  while (x) {
    x /= b;
    ++r;
  }
  return r;
}

struct FenwickTree {
  vector<ll> b1, b2;
  ll n;

  FenwickTree(ll n) {
    this->n = n + 1;
    b1.assign(n + 1, 0);
    b2.assign(n + 1, 0);
  }

  FenwickTree(vector<ll> &a) : FenwickTree(a.size()) {
    for (ll i = 0; i < a.size(); ++i) {
      add(i, a[i]);
    }
  }

  void add(vector<ll> &b, ll idx, ll x) {
    for (++idx; idx <= n; idx += idx & -idx) {
      b[idx] += x;
    }
  }

  void add(ll l, ll r, ll x) {
    add(b1, l, x);
    add(b1, r + 1, -x);
    add(b2, l, x * (l - 1));
    add(b2, r + 1, -x * r);
  }

  void add(ll idx, ll x) { add(idx, idx, x); }

  ll sum(vector<ll> &b, ll idx) {
    ll total = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
      total += b[idx];
    }
    return total;
  }

  ll sum(ll idx) { return sum(b1, idx) * idx - sum(b2, idx); }

  ll sum(ll l, ll r) { return sum(r) - sum(l - 1); }
};

int main() {
  FASTIO();

  ll n;
  cin >> n;

  struct FenwickTree ft(n);
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    ft.add(i, x);
  }

  ll m;
  cin >> m;
  for (ll i = 0; i < m; ++i) {
    ll t, x, y, z;
    cin >> t >> x >> y;
    if (t) {
      cin >> z;
      ft.add(x, y, z);
    } else {
      cout << ft.sum(x, y) << '\n';
    }
  }
}