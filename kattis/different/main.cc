#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  long long a, b;
  while (cin >> a >> b) {
    if (a < b) {
      cout << b - a;
    } else {
      cout << a - b;
    }
    cout << '\n';
  }
}