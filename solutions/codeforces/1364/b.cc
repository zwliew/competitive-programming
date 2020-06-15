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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> ans = {arr[0]};
    for (int i = 1; i < n - 1; ++i) {
      if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
          (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
        ans.emplace_back(arr[i]);
      }
    }
    ans.emplace_back(arr.back());
    
    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i) {
      if (i) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
}

