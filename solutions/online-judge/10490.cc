/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <ext/numeric>
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
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

  const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  const vector<int> mersennePrimes = {2, 3, 5, 7, 13, 17, 19, 31};

  int64_t n;
  while (cin >> n && n) {
    if (find(primes.begin(), primes.end(), n) == primes.end()) {
      cout << "Given number is NOT prime! NO perfect number is available.\n";
      continue;
    }

    // Up till a very large N, perfect numbers only exist for Mersenne primes.
    if (find(mersennePrimes.begin(), mersennePrimes.end(), n) ==
        mersennePrimes.end()) {
      cout << "Given number is prime. But, NO perfect number is available.\n";
      continue;
    }

    int64_t x = 1ll << (n - 1);
    int64_t y = (1ll << n) - 1;

    cout << "Perfect: " << x * y << "!\n";

    // Slower solution by finding all divisors.
    // vector<int64_t> xDivs, yDivs;
    // int64_t i;
    // for (i = 1; i * i < x; ++i) {
    //   if (x % i == 0) {
    //     xDivs.push_back(i);
    //     xDivs.push_back(x / i);
    //   }
    // }
    // if (i * i == x) {
    //   xDivs.push_back(i);
    // }

    // for (i = 1; i * i < y; ++i) {
    //   if (y % i == 0) {
    //     yDivs.push_back(i);
    //     yDivs.push_back(y / i);
    //   }
    // }
    // if (i * i == y) {
    //   yDivs.push_back(i);
    // }

    // unordered_set<int64_t> divs;
    // for (auto xd : xDivs) {
    //   for (auto yd : yDivs) {
    //     divs.insert(xd * yd);
    //   }
    // }

    // int64_t sum = 0;
    // for (auto d : divs) {
    //   sum += d;
    // }

    // if (sum - x * y == x * y) {
    //   cout << "Perfect: " << x * y << "!";
    // } else {
    //   cout << "Given number is prime. But, NO perfect number is available.";
    // }
    // cout << "\n";
  }
}
