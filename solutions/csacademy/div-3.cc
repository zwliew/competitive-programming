#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  int ans = 0;
  while (x > 1) {
    if (x % 3 == 0) {
      x /= 3;
    } else if (x % 3 == 1 || x == 2) {
      --x;
    } else {
      ++x;
    }
    ans++;
  }
  cout << ans;
}