#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t N, M;
  cin >> N >> M;

  vector<vector<uint32_t>> v(N, vector<uint32_t>(M));
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < M; j++) {
      cin >> v[i][j];
    }
    sort(v[i].begin(), v[i].end());
  }

  sort(v.begin(), v.end());

  for (auto ni : v) {
    for (uint32_t i = 0; i < ni.size() - 1; i++) {
      cout << ni[i] << ' ';
    }
    cout << ni.back() << '\n';
  }
}