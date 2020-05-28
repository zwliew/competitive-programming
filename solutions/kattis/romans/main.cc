#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  double x;
  cin >> x;

  cout << (int)(x * (5280000. / 4854.) + .5);
}