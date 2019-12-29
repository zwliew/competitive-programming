#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  if (b >= a) {
    cout << "Dr. Chaz will have " << (b - a) << " piece"
         << (b - a != 1 ? "s " : " ") << "of chicken left over!";
  } else {
    cout << "Dr. Chaz needs " << (a - b) << " more piece"
         << (a - b != 1 ? "s " : " ") << "of chicken!";
  }
}