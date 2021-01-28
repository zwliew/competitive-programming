#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

template <int P, int M>
class string_hash {
 private:
  std::vector<int> h, pw;

 public:
  string_hash(std::string& s) {
    h.resize(s.size() + 1);
    h[0] = 0;
    for (int i = 0; i < s.size(); ++i) {
      h[i + 1] = ((int64_t)h[i] * P + s[i]) % M;
    }

    pw.resize(s.size() + 1);
    pw[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      pw[i] = ((int64_t)pw[i - 1] * P) % M;
    }
  }

  int compute(int l, int r) {
    return ((h[r] - ((int64_t)h[l] * pw[r - l]) % M) + M) % M;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  const int p = 9973;
  const int m = 1e9 + 7;
  string T, S;
  while (getline(cin, T) && getline(cin, S)) {
    string_hash<9973, (int)1e9 + 9> sh(S);
    string_hash<9973, (int)1e9 + 9> th(T);

    for (int i = 0; i < (int)S.size() - T.size() + 1; ++i) {
      if (sh.compute(i, i + T.size()) == th.compute(0, T.size())) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
}
