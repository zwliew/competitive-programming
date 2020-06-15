/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int x, n;
  cin >> x >> n;
  multiset<int> lengths;
  set<int> pos;
  lengths.emplace(x);
  while (n--) {
    int p;
    cin >> p;
    if (p > 0 && p < x) {
      auto lb = pos.lower_bound(p);
      int lowerIdx = 0, upperIdx = x;
      if (lb != pos.begin()) {
        lowerIdx = *prev(lb);
      }
      if (lb != pos.end()) {
        upperIdx = *lb;
      }
      lengths.erase(lengths.find(upperIdx - lowerIdx));
      lengths.emplace(p - lowerIdx);
      lengths.emplace(upperIdx - p);
    }
    pos.emplace(p);
    cout << *lengths.rbegin() << ' ';
  }
}
