#include <iostream>

using namespace std;

int main() {
  int n, r, k;
  cin >> n >> r >> k;
  cout << abs(r - k) << ' ' << n - abs(n - r - k);
}