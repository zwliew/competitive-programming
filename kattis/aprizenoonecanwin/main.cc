#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  if (n < 2) {
    cout << 1;
    return 0;
  }

  vector<int> v(n, 0);
  while (--n + 1) {
    cin >> v[n];
  }

  sort(v.begin(), v.end());

  int i = 1;
  for (; i < v.size(); ++i) {
    if (v[i] + v[i - 1] > x) {
      break;
    }
  }

  cout << i;
}