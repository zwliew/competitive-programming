#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--)
  {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (auto &x : P)
      cin >> x;

    int64_t acc = P[0];
    int64_t ans = 0;
    for (int i = 1; i < N; ++i)
    {
      ans = max(ans, ((int64_t)100 * P[i] - K * acc + K - 1) / K);
      acc += P[i];
    }
    cout << ans << "\n";

    // Binary search solution O(nlogn)
    // int64_t l = -1, r = 1e11;
    // while (r - l > 1)
    // {
    //   int64_t m = l + (r - l) / 2;
    //   int64_t acc = P[0] + m;
    //   bool ok = true;
    //   for (int i = 1; ok && i < N; ++i)
    //   {
    //     if ((int64_t)P[i] * 100 > K * acc)
    //     {
    //       ok = false;
    //     }
    //     acc += P[i];
    //   }
    //   if (ok)
    //   {
    //     r = m;
    //   }
    //   else
    //   {
    //     l = m;
    //   }
    // }
    // cout << r << "\n";
  }
}

