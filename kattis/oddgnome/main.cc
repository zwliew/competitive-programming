#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int g;
    cin >> g;
    int a, b;
    cin >> a;
    bool t = false;
    for (int gi = 2; gi <= g; ++gi) {
      cin >> b;
      if (t) continue;
      if (b != a + 1) {
        cout << gi << '\n';
        t = true;
      }
      a = b;
    }
  }
}