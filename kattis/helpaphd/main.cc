#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s == "P=NP") {
      cout << "skipped\n";
    } else {
      int a = 0, b = 0;
      bool n = false;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
          n = true;
          continue;
        }
        if (!n) {
          a = a * 10 + s[i] - '0';
        } else {
          b = b * 10 + s[i] - '0';
        }
      }
      cout << a + b << '\n';
    }
  }
}