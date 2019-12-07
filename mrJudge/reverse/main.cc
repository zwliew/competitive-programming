#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);

  vector<string> v;
  // int last_pos = 0, pos;
  // while ((pos = s.find(' ', last_pos)) != string::npos) {
  //   v.emplace_back(s.substr(last_pos, pos - last_pos));
  //   last_pos = pos + 1;
  // }
  // v.emplace_back(s.substr(last_pos));

  vector<string> dv;
  int is_word = 0; // 1 == word, 2 == non-word
  int last_pos = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (!isalpha(c)) {
      if (is_word == 1) {
        v.emplace_back(s.substr(last_pos, i - last_pos));
        last_pos = i;
      } else if (!is_word) {
        v.emplace_back("");
      }
      is_word = 2;
    } else {
      if (is_word == 2) {
        dv.emplace_back(s.substr(last_pos, i - last_pos));
        last_pos = i;
      }
      is_word = 1;
    }
  }
  if (is_word == 1) {
    v.emplace_back(s.substr(last_pos, s.size() - last_pos));
    dv.emplace_back("");
  } else if (is_word == 2) {
    dv.emplace_back(s.substr(last_pos, s.size() - last_pos));
  }

  // cout << '\n' << v.size() << ' ' << dv.size() << '\n';

  // cout << '\n';
  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << dv[i];
  // }
  // cout <<'\n';

  for (int i = 0; i < v.size(); i++) {
    string vi = v[i];
    int fp = 0;
    int bp = vi.size() - 1;
    while (fp < bp) {
      char fi = vi[fp];
      if (!isalpha(fi)) {
        ++fp;
        continue;
      }

      char bi = vi[bp];
      if (!isalpha(bi)) {
        --bp;
        continue;
      }

      bool fu = isupper(fi);
      bool bu = isupper(bi);

      vi[fp] = fu ? toupper(bi) : tolower(bi);
      vi[bp] = bu ? toupper(fi) : tolower(fi);
      ++fp;
      --bp;
    }
    v[i] = vi;
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << dv[i];
  }
}