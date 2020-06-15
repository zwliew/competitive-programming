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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, k, q;
  cin >> n >> k >> q;
  vector<int> tempDiff(200002);
  while (n--) {
    int l, r;
    cin >> l >> r;
    tempDiff[l]++;
    tempDiff[r + 1]--;
  }

  vector<int> admissable(200001);
  int cnt = 0;
  for (int i = 1; i <= 200000; ++i) {
    cnt += tempDiff[i];
    if (cnt >= k) {
      admissable[i] = 1;
    }
  }

  partial_sum(admissable.begin(), admissable.end(), admissable.begin());

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << admissable[r] - admissable[l - 1] << '\n';
  }
}
