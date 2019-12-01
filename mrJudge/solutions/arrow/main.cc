#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;
  cin >> h >> w;

  string s(w - (h - 1) / 2, '*');
  for (int i = 0; i < (h -1) / 2; i++) {
    cout << string(i, ' ') << s << string(w - i - s.size(), ' ') << '\n';
  }
  for (int i = (h - 1) / 2; i > 0; i--) {
    cout << string(i, ' ') << s << string(w - i - s.size(), ' ') << '\n';
  }
  cout << s << string(w - s.size(), ' ');
}