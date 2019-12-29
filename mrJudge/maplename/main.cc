#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  char r;
  string s;
  cin >> r >> s;

  switch (r) {
    case 'A':
      cout << 'o' << string(s.size(), '-') << "o\n";
      cout << '|' << s << '|' << '\n';
      cout << 'o' << string(s.size(), '-') << "o\n";
      break;
    case 'K':
      cout << 'x' << string(s.size(), '-') << "x\n";
      cout << '|' << s << '|' << '\n';
      cout << 'x' << string(s.size(), '-') << "x\n";
      break;
    case 'H':
      for (int i = 0; i < s.size() + 2; i++) {
        if (i % 2 == 0) {
          cout << 'o';
        } else {
          cout << 'x';
        }
      }
      cout << '\n';
      cout << 'x' << s << (s.size() % 2 == 0 ? 'o' : 'x') << '\n';
      for (int i = 0; i < s.size() + 2; i++) {
        if (i % 2 == 0) {
          cout << 'o';
        } else {
          cout << 'x';
        }
      }
      break;
    case 'R':
      const int even = s.size() % 2 == 0;
      const size_t pad_cnt = s.size() / 2;
      cout << 'o' << string(pad_cnt - even, '-') << '+' << string(pad_cnt, '-') << "o\n";
      cout << '|' << s << '|' << '\n';
      cout << 'o' << string(pad_cnt - even, '-') << '+' << string(pad_cnt, '-') << "o\n";
      break;
  }
}