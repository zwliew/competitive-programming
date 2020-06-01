#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;
using ld = long double;
int main() {
  int s, q, k;
  cin >> s >> q >> k;
  int arr[q];
  for (int i = 0; i < q; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + q);

  ld ans = s;
  for (int i = 0; i < q; ++i) {
    ld pos = ans * (arr[i] + 100) / 100;
    if (pos < ans + k) {
      ans += k;
    } else {
      ans = pos;
    }
  }

  cout << fixed << setprecision(7) << ans;
}