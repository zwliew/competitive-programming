#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  while (n) {
    cout << n << " bottle" << (n > 1 ? "s " : " ") << "of " << s
         << " on the wall, " << n << " bottle" << (n > 1 ? "s " : " ") << "of "
         << s << ".\n";
    if (n-- > 1) {
      cout << "Take one down, pass it around, " << n << " bottle"
           << (n > 1 ? "s " : " ") << "of " << s << " on the wall.\n\n";
    } else {
      cout << "Take it down, pass it around, no more bottles of " << s << ".";
    }
  }
}