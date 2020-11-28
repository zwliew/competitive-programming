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

int64_t toDec(string& s, int b) {
  int64_t res = 0;
  for (char c : s) {
    int dig;
    if (c >= 'A') {
      dig = c - 'A' + 10;
    } else {
      dig = c - '0';
    }
    res = res * b + dig;
  }
  return res;
}

const int MAXN = 4194304;
vector<bool> p(MAXN + 1, true);
vector<int> primes;
bool isPrime(int64_t x) {
  if (x <= MAXN)
    return p[x];
  for (int d : primes) {
    if ((int64_t)d * d > x)
      break;
    if (x % d == 0)
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

  p[0] = p[1] = false;
  for (int i = 2; i * i <= MAXN; ++i) {
    if (p[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        p[j] = false;
      }
    }
  }
  for (int i = 2; i <= MAXN; i += 1 + (i & 1)) {
    if (p[i])
      primes.push_back(i);
  }

  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    bool posOctal = true;
    bool posBinary = true;
    bool posDecimal = true;
    bool posHex = true;
    for (char c : S) {
      if (c >= 'A') {
        posDecimal = false;
      }
      if (c >= '8') {
        posOctal = false;
      }
      if (c >= '2') {
        posBinary = false;
      }
    }

    vector<int> bases = {16};
    if (posDecimal)
      bases.push_back(10);
    if (posOctal)
      bases.push_back(8);
    if (posBinary)
      bases.push_back(2);

    int prime = 0;
    for (int b : bases) {
      int64_t x = toDec(S, b);
      if (isPrime(x)) {
        ++prime;
      }
    }
    int cd = gcd(bases.size(), prime);
    cout << prime / cd << "/" << bases.size() / cd << "\n";
  }
}
