#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string s, r;
  for (int i = 0; i < N; i++) {
    cin >> s;
    r = s[0];
    int pos, last_pos = 0;
    while ((pos = s.find('_', last_pos)) != string::npos) {
      last_pos = pos + 1;
      r += s[last_pos];
    }
    if (r.size() > 5) {
      cout << "CENSORED\n";
    } else {
      cout << r << '\n';
    }
  }
}