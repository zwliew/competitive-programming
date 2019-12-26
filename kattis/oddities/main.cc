#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a;
  cin >> n;
  while (n--) {
    cin >> a;
    cout << a << " is " << (a % 2 == 0 ? "even" : "odd") << '\n';
  }
}