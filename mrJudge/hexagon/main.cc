#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned int N;
  cin >> N;

  for (unsigned int i = 0; i < N - 1; i++) {
    cout << string(N - 1 - i, ' ') << string(N + i * 2, 'x') << '\n';
  }
  for (int i = N - 1; i >= 0; i--) {
    cout << string(N - 1 - i, ' ') << string(N + i * 2, 'x') << '\n';
  }

  return 0;
}