#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    string s;
    cin >> n >> s;
    int ttmax = 0, ctmax = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      q.emplace(s[i] - '0');
      ctmax += s[i] - '0';
      if (i >= ceil(n / 2.)) {
        ctmax -= q.front();
        q.pop();
      }
      if (ctmax > ttmax) ttmax = ctmax;
    }
    cout << "Case #" << ti << ": " << ttmax << endl;
  }
}