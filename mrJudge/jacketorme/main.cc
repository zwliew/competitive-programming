#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  string r = "RANALD";
  string j = "JACKET";

  int cnt_r = 0, cnt_j = 0;
  int pos, last_pos = 0;

  while ((pos = s.find(r, last_pos)) != string::npos) {
    ++cnt_r;
    last_pos = pos + 1;
  }

  last_pos = 0;

  while ((pos = s.find(j, last_pos)) != string::npos) {
    ++cnt_j;
    last_pos = pos + 1;
  }

  cout << (cnt_j > cnt_r ? j : r);
}