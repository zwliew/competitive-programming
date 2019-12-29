#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (!i || (s[i - 1] == 45 && isupper(s[i]))) {
      cout << s[i];
    }
  }
}