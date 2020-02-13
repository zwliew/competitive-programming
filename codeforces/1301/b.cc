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
    int a;
    cin >> a;

    vector<int> v1;
    set<int> v2;
    for (int i = 0; i < a; ++i) {
      int x;
      cin >> x;
      v1.eb(x);
      if (x != -1 && i > 0 && v1[i - 1] == -1) {
        v2.emplace(x);
      } else if (x == -1 && i > 0 && v1[i - 1] != -1) {
        v2.emplace(v1[i - 1]);
      }
    }

    if (!v2.size()) {
      cout << 0 << ' ' << 0 << '\n';
      continue;
    }

    int mx = 0;
    int avg = round((*v2.rbegin() + *v2.begin()) / 2);
    for (int i = 0; i < v1.size() - 1; ++i) {
      mx = max(mx, abs((v1[i] == -1 ? avg : v1[i]) -
                       (v1[i + 1] == -1 ? avg : v1[i + 1])));
    }
    cout << mx << ' ' << avg << '\n';
  }
}
