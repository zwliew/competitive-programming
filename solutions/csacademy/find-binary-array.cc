#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans[n];
  int prev;
  cin >> prev;
  for (int i = 1; i < n; ++i) {
    int cur;
    cin >> cur;
    if (cur > prev) {
      ans[i - 1] = 0;
    } else {
      ans[i - 1] = 1;
    }
    prev = cur;
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> prev;
  }
  int cur;
  cin >> cur;
  if (cur < prev) {
    ans[n - 1] = 0;
  } else {
    ans[n - 1] = 1;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i];
  }
}