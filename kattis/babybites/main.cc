#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if (s == "mumble") {
      continue;
    } else {
      int si = stoi(s);
      if (si != i) {
        cout << "something is fishy";
        return 0;
      }
    }
  }
  cout << "makes sense";
}