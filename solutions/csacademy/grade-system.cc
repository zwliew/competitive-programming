#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cmin = 1e9, cmax = -1e9;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    total += x;
    cmin = min(cmin, x);
    cmax = max(cmax, x);
  }
  cout << (total - cmin - cmax) / (n - 2);
}