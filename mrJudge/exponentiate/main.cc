#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint64_t T;
  cin >> T;
  for (uint64_t i = 0; i < T; i++) {
    uint64_t A, B, M;
    cin >> A >> B >> M;

    unordered_map<uint64_t, uint64_t> m;
    uint64_t tmp;
    uint64_t j = 1;
    uint64_t acc = A % M;
    m[1] = acc;
    while (j < B) {
      tmp = B - j;
      if (tmp % 2 != 0) {
        ++j;
        acc = (acc * (A % M)) % M;
        m[j] = acc;
      } else {
        uint64_t i;
        for (i = 2; i <= tmp; i *= 2) {
          if (m.find(i) == m.end()) {
            m[i] = (m[i / 2] * m[i / 2]) % M;
          }
        }

        i /= 2;
        acc = (acc * m[i]) % M;
        j += i;
      }
    }

    cout << acc << '\n';
  }
}