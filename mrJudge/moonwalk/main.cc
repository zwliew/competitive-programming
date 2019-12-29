#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, c;
  cin >> n >> m >> c;

  int s, e, t;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < c; ++i) {
    cin >> s >> e >> t;
    e -= s + t;
    if (e > 0) {
      q.emplace(e);
    }
  }

  while (q.size() > m) {
    q.pop();
  }

  while (!q.empty()) {
    n -= q.top();
    q.pop();
  }

  cout << n;
}