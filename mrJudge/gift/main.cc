#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;

  unsigned int cnt = 0;

  int prev;
  cin >> prev;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    if (prev > x && prev - x >= k) {
      cnt++;
    }
    prev = x;
  }

  cout << cnt;

  return 0;
}