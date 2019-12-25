#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  array<int, 3> v;
  cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  int d = min(v[1] - v[0], v[2] - v[1]);
  for (int i = 0; i < v.size() - 1; ++i) {
    if (v[i + 1] - v[i] > d) {
      cout << ((v[i + 1] + v[i]) >> 1);
      return 0;
    }
  }
  cout << v[2] + d;
}