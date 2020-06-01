#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!x) {
      ans += (long long)cur * (cur + 1) / 2;
      cur = 0;
    } else {
      ++cur;
    }
  }
  ans += (long long)cur * (cur + 1) / 2;

  cout << ans;
}