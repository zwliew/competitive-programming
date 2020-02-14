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
#include <condition_variable>
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

int main() {
  FASTIO();

  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll z = n - m;
    ll g = m + 1;
    ll k = z / (m + 1);
    cout << n * (n + 1) / 2 - k * (k + 1) / 2 * g - (k + 1) * (z % g) << '\n';
  }
}

// 1 1 - 1 - 1
// 2 1 - 10 - 2
// 2 2 - 11 - 3
// 3 1 - 010 - 4
// 3 2 - 101 - 5
// 3 3 - 111 - 6
// 4 1 - 0100 - 6
// 4 2 - 0101 - 8
// 4 3 - 0111 - 9
// 4 4 - 1111 - 10
// 5 1 - 00100 - 9
// 5 2 - 01010 - 12
// 5 3 - 10101 - 13
// 5 4 - 11101 - 14
// 5 5 - 11111 - 15
// 6 1 - 000100 - 12
// 6 2 - 010100 - 16
// 6 3 - 010101 - 18
// 6 4 - 101101 - 19
// 6 5 - 111101 - 20
// 6 6 - 111111 - 21
// 7 1 - 0001000 - 16
// 7 2 - 0010100 - 21