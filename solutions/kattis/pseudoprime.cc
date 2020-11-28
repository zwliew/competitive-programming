#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int binpow(int a, int b, const int m) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (int64_t)res * a % m;
    }
    a = (int64_t)a * a % m;
    b >>= 1;
  }
  return res;
}

const int MAXN = 31623;
vector<bool> isPrime(MAXN + 1, 1);
vector<int> primes;
bool testPrime(int n) {
  if (n <= MAXN)
    return isPrime[n];
  for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; ++i) {
    if (n % primes[i] == 0)
      return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  for (int i = 2; i * i <= MAXN; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 2; i <= MAXN; i += 1 + (i & 1)) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  int p, a;
  while (cin >> p >> a && p && a) {
    int res = binpow(a, p, p);
    if (!testPrime(p) && res == a) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
