#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  string ans;
  bool used = false;
  for (char c : s) {
    if (c == 'A') {
      if (!used) {
        ans += c;
        used = true;
      }
    } else {
      ans += c;
      used = false;
    }
  }
  cout << ans;
}