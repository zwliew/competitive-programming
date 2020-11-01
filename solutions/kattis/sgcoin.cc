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

long long H(long long previousHash, string& transaction, long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int64_t n;
  cin >> n;
  // ((n * 31 + x) * 7 + token) % (1e9 + 7)
  // n * 217 + x * 7 + token = 1e7
  // x = 'a'
  // token = 1e7 - 217 * n - 7 * 'a'
  for (int i = 0; i < 2; ++i) {
    int64_t token =
        ((1'000'000'0 - 217 * n - 7 * 'a') % 1'000'000'007 + 1'000'000'007) %
        1'000'000'007;
    string transaction = "a";
    cout << transaction << " " << token << "\n";
    n = H(n, transaction, token);
  }
}
