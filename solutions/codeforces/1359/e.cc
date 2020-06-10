/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

const int MOD = 998244353;

int mpow(int b, int e) {
  int ans = 1;
  while (e) {
    if (e & 1) {
      ans = ((long long)ans * b) % MOD;
    }
    b = ((long long)b * b) % MOD;
    e >>= 1;
  }
  return ans;
}
int mmult(int a, int b) { return ((long long)a * b) % MOD; }
int mdiv(int num, int denom) { return mmult(num, mpow(denom, MOD - 2)); }
void calcFactorial(vector<int> &fact, int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = mmult(fact[i - 1], i);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<int> fact(n + 1);
  calcFactorial(fact, n);
  for (int i = 1; i <= n; ++i) {
    if (n / i < k) break;
    int d = n / i;
    ans =
        ((long long)ans + mdiv(fact[d - 1], mmult(fact[k - 1], fact[d - k]))) %
        MOD;
  }
  cout << ans;
}
