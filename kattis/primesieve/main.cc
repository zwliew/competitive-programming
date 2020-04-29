#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

using ll = long long;
using ld = long double;

bitset<100000002> primes;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Using Sieve of Eratosthenes works for around 1e8
  int n, q;
  cin >> n >> q;

  primes.set();
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i <= n; ++i) {
    if (!primes[i]) continue;
    for (int j = i * i; j <= n; j += i) {
      primes[j] = 0;
    }
  }

  int count = 0;
  for (int i = 2; i <= n; ++i) {
    if (primes[i]) ++count;
  }

  cout << count << '\n';
  while (q--) {
    int x;
    cin >> x;
    cout << primes[x] << '\n';
  }
}
