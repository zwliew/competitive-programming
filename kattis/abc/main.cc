#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  array<int, 3> v;
  cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'C')
      cout << v[2] << ' ';
    else if (c == 'B')
      cout << v[1] << ' ';
    else
      cout << v[0] << ' ';
  }
}