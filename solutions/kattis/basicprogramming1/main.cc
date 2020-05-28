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

int main() {
  FASTIO();

  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  switch (t) {
    case 1: {
      cout << 7;
      break;
    }
    case 2: {
      if (a[0] > a[1])
        cout << "Bigger";
      else if (a[0] == a[1])
        cout << "Equal";
      else
        cout << "Smaller";
      break;
    }
    case 3: {
      vector<int> v = {a[0], a[1], a[2]};
      nth_element(v.begin(), v.begin() + 1, v.end());
      cout << v[1];
      break;
    }
    case 4: {
      ll sum = 0;
      for (int vi : a) {
        sum += vi;
      }
      cout << sum;
      break;
    }
    case 5: {
      ll sume = 0;
      for (int vi : a) {
        if (vi & 1) continue;
        sume += vi;
      }
      cout << sume;
      break;
    }
    case 6: {
      string s;
      for (int vi : a) {
        s += (vi % 26) + 'a';
      }
      cout << s;
      break;
    }
    case 7: {
      unordered_set<int> vis;
      int i = 0;
      while (1) {
        if (vis.count(i)) {
          cout << "Cyclic";
          break;
        } else if (i >= a.size() || i < 0) {
          cout << "Out";
          break;
        } else if (i == a.size() - 1) {
          cout << "Done";
          break;
        }
        vis.emplace(i);
        i = a[i];
      }
      break;
    }
  }
}
