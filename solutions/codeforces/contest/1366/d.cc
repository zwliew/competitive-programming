/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  const int MAXP = 10000000;
  bitset<MAXP + 1> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 4; i <= MAXP; i += 2) {
    isPrime[i] = 0;
  }
  for (int i = 3; i * i <= MAXP; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAXP; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  vector<int> primes = {2};
  for (int i = 3; i <= MAXP; i += 2) {
    if (isPrime[i]) {
      primes.emplace_back(i);
    }
  }

  vector<pair<int, int>> ans;
  for (auto x : a) {
    vector<int> div;
    int cur = x;
    for (auto p : primes) {
      if (p * p > cur) break;
      if (cur % p == 0) {
        while (cur % p == 0) {
          cur /= p;
        }
        div.emplace_back(p);
      }
    }
    if (cur > 1) div.emplace_back(cur);

    if (div.size() == 1) {
      ans.emplace_back(-1, -1);
    } else {
      int complement = 1;
      for (int i = 1; i < (int)div.size(); ++i) {
        complement *= div[i];
      }
      ans.emplace_back(
          div[0], accumulate(div.begin() + 1, div.end(), 1, multiplies<int>()));
    }
  }

  for (auto &[x, y] : ans) {
    cout << x << ' ';
  }
  cout << '\n';
  for (auto &[x, y] : ans) {
    cout << y << ' ';
  }
}

