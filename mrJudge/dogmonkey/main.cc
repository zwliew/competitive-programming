#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int64_t n, m;
  cin >> n >> m;

  if (abs(n - m) > 1) {
    cout << 0;
    return 0;
  }

  const int64_t mod = 1e9 + 7;
  const int64_t lo = n > m ? m : n;
  int64_t r = 1;
  for (int64_t i = 2; i <= lo; i++) {
    r = (((r * i) % mod) * i) % mod;
  }
  if (n != m) {
    r = (r * (lo + 1)) % mod;
  } else {
    r = (r * 2) % mod;
  }

  cout << r;
}

/*
2-2 -> 3 spots -> 2/3
3-3 -> 4 spots -> 2/4
4-4 -> 5 spots -> 2/5
5-5 -> 6 spots -> 2/6
*/