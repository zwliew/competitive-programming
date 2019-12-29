#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, dm;
  cin >> n >> dm;
  int c = 0;
  while (n--) {
    int di;
    cin >> di;
    if (di <= dm) {
      cout << "It hadn't snowed this early in " << c << " years!";
      return 0;
    }
    ++c;
  }
  cout << "It had never snowed this early!";
}