#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int x, n;
  cin >> x >> n;
  int t = x;
  while (n--) {
    int p;
    cin >> p;
    t += (x - p);
  }
  cout << t;
}