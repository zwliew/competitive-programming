#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int r, e, c;
    cin >> r >> e >> c;
    if (c + r > e) {
      cout << "do not advertise\n";
    } else if (c + r < e) {
      cout << "advertise\n";
    } else {
      cout << "does not matter\n";
    }
  }
}