#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  int ans = 1;
  int dp[n];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[i] % arr[j] == 0) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans;
}