#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  int n;
  cin >> s >> n;
  if ((s == "OCT" && n == 31) || (n == 25 && s == "DEC")) {
    cout << "yup";
  } else {
    cout << "nope";
  }
}