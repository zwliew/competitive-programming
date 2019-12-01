#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint16_t n;
  cin >> n;

  for (uint16_t i = 0; i < n; i++) {
    string s;
    cin >> s;

    bool is_hexa = true;
    for (size_t j = 1; j < s.size(); j++) {
      if ((s[j] < 65 || s[j] > 70) && !isdigit(s[j])) {
        is_hexa = false;
        break;
      }
    }

    if (!is_hexa) {
      cout << "Not Hexadecimal\n";
    } else {
      cout << "Hexadecimal\n";
    }
  }
}