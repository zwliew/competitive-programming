/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

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

  long long n;
  cin >> n;
  vector<int> first, second;

  if (n * (n + 1) % 4) {
    cout << "NO";
    return 0;
  }
  
  // Method using mathematical induction on n = 4k + 3 or n = 4k
  // for (int i = (n % 4 == 3 ? 4 : 1); i <= n; i += 4) {
  //   first.emplace_back(i);
  //   first.emplace_back(i + 3);
  //   second.emplace_back(i + 1);
  //   second.emplace_back(i + 2);
  // }
  // if (n % 4 == 3) {
  //   first.emplace_back(1);
  //   first.emplace_back(2);
  //   second.emplace_back(3);
  // }

  // Method using greedy
  long long rem = n * (n + 1) / 4;
  for (int i = n; i; --i) {
    if (i <= rem) {
      rem -= i;
      first.emplace_back(i);
    } else {
      second.emplace_back(i);
    }
  }

  cout << "YES\n";
  cout << first.size() << '\n';
  for (auto x : first) cout << x << ' ';
  cout << '\n';
  cout << second.size() << '\n';
  for (auto x : second) cout << x << ' ';
}
