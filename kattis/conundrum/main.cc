#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  array<char, 3> a = {'P', 'E', 'R'};
  int i = 0;
  int cnt = 0;
  for (char sc : s) {
    if (sc != a[i]) ++cnt;
    i = (i + 1) % 3;
  }
  cout << cnt;
}