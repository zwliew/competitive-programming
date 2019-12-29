#include <bits/stdc++.h>
using namespace std;
int main() {
  string i;
  cin >> i;

  for (char c : i) {
    if (!isdigit(c)) {
      transform(i.begin(), i.end(), i.begin(), ::toupper);
      cout << i;
      return 0;
    }
  }
  cout << stoi(i) * 2;
  return 0;
}
