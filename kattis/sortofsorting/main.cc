#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  while (cin >> n && n) {
    vector<string> v(n);
    for (int i = 0; i < v.size(); ++i) {
      cin >> v[i];
    }
    stable_sort(v.begin(), v.end(), [](const auto &l, const auto &r) {
      if (l[0] != r[0]) {
        return l[0] < r[0];
      }

      return l[1] < r[1];
    });
    for (auto s : v) {
      cout << s << '\n';
    }
    cout << '\n';
  }
}