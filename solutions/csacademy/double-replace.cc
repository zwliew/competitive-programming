#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < (int)s.size(); ++i) {
    string sub = s.substr(i, a.size());
    if (sub == a) {
      s = s.substr(0, i) + b + s.substr(i + a.size());
      i += a.size() - 1;
    } else if (sub == b) {
      s = s.substr(0, i) + a + s.substr(i + a.size());
      i += a.size() - 1;
    }
  }
  cout << s;
}