#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int s;
  cin >> s;
  cout << s << ":\n";

  for (int x = 2; x < s; ++x) {
    if (s % (x * 2 - 1) == 0 || (s + x - 1) % (x * 2 - 1) == 0) {
      cout << x << ',' << x - 1 << '\n';
    }
    if (s % (x * 2) == 0 || (s + x) % (x * 2) == 0) {
      cout << x << ',' << x << '\n';
    }
  }
}