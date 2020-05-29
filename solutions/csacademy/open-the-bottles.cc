#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int arr[3];
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    ans += arr[0];
  }
  cout << ans;
}