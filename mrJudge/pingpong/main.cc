// #include "pingpong.h"
#include <bits/stdc++.h>
using namespace std;

string winner(string S) {
  int rtot = 0, ptot = 0;
  int r = 0, p = 0;
  for (char c : S) {
    if (c == 'R') {
      r++;
    } else if (c == 'P') {
      p++;
    }

    if (r >= 11 && r >= p + 2) {
      r = 0;
      p = 0;
      rtot++;
    } else if (p >= 11 && p >= r + 2) {
      r = 0;
      p = 0;
      ptot++;
    }

    if (rtot == 3) {
      return "Rar";
    } else if (ptot == 3) {
      return "Potato";
    }
  }

  return rtot > ptot ? "Rar" : "Potato";
}

int main() {
  string s;
  cin >> s;
  cout << winner(s);
}