#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int t[26];
  for (int i = 0; i < 26; ++i) cin >> t[i];
  int ans = 0;
  for (char c : s) {
    ans += t[c - 'a'];
  }
  cout << ans;
}