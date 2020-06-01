#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    bool anomaly = true;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (abs(arr[i] - arr[j]) <= k) {
        anomaly = false;
        break;
      }
    }
    if (anomaly) ++ans;
  }

  cout << ans;
}