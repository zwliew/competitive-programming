#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  float uas = 0;
  char worst_h2 = 'A';
  size_t sep = s.find_first_of('/');
  for (size_t i = 0; i < sep; i++) {
    if (s[i] > worst_h2) {
      worst_h2 = s[i];
    }

    switch (s[i]) {
      case 'E':
        uas += 10;
        break;
      case 'S':
        uas +=5;
        break;
      case 'A':
        uas += 20;
        break;
      case 'B':
        uas += 17.5;
        break;
      case 'C':
        uas += 15;
        break;
      case 'D':
        uas += 12.5;
        break;
    }
  }

  for (size_t i = sep + 1; i < s.size(); i++) {
    switch (s[i]) {
      case 'E':
        uas += 5;
        break;
      case 'S':
        uas += 2.5;
        break;
      case 'A':
        uas += 10;
        break;
      case 'B':
        uas += 8.75;
        break;
      case 'C':
        uas += 7.5;
        break;
      case 'D':
        uas += 6.25;
        break;
    }
  }

  if (sep == 4 && s.size() == 7) {
    switch (worst_h2) {
      case 'E':
        uas -= 5;
        break;
      case 'S':
        uas -= 2.5;
        break;
      case 'A':
        uas -= 10;
        break;
      case 'B':
        uas -= 8.75;
        break;
      case 'C':
        uas -= 7.5;
        break;
      case 'D':
        uas -= 6.25;
        break;
    }
  }

  cout << ceil(uas);
}