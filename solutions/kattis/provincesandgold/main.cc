#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int g, s, c;
  cin >> g >> s >> c;
  int t = g * 3 + s * 2 + c;

  if (t >= 8) {
    cout << "Province or ";
  } else if (t >= 5) {
    cout << "Duchy or ";
  } else if (t >= 2) {
    cout << "Estate or ";
  }

  if (t >= 6) {
    cout << "Gold";
  } else if (t >= 3) {
    cout << "Silver";
  } else {
    cout << "Copper";
  }
}