#include <string>
#include <vector>

// P = 31 or 9973
// M = 1e9 + 9 or 1e9 + 7, 998244353
template <int P, int M> class string_hash {
private:
  std::vector<int> h, pw;
  int N;

public:
  string_hash(std::string &S) {
    N = S.size();

    h.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
      h[i] = ((int64_t)h[i - 1] * P + S[i - 1]) % M;
    }

    pw.resize(N + 1);
    pw[0] = 1;
    for (int i = 1; i <= N; ++i) {
      pw[i] = ((int64_t)pw[i - 1] * P) % M;
    }
  }

  // Returns the hash of the substring in the range [l, r)
  int compute(int l, int r) {
    assert(l >= 0 && r >= l && r <= N);
    return ((h[r] - ((int64_t)h[l] * pw[r - l]) % M) + M) % M;
  }
};
