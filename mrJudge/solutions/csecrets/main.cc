#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  int n;
  cin >> n;

  int pos = 0;
  while (pos < a.size()) {
    cout << a.substr(pos, n) << b.substr(pos, n);
    pos += n;
  }
}
