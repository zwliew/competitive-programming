#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int c = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x < 0) ++c;
  }
  cout << c;
}