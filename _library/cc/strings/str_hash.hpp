#ifndef STR_HASH_CPP
#define STR_HASH_CPP

#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

// P = 31 or 9973 or 239017
// M = 1e9 + 9 or 1e9 + 7, 998244353
namespace strings {
template <int P, int M> class str_hash {
public:
  str_hash(const std::string &s) : N(s.size()) {
    h.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
      h[i] = ((std::int64_t)h[i - 1] * P + s[i - 1]) % M;
    }

    pw.resize(N + 1);
    pw[0] = 1;
    for (int i = 1; i <= N; ++i) {
      pw[i] = ((std::int64_t)pw[i - 1] * P) % M;
    }
  }

  // Returns the hash of the substring in the range [l, r)
  int hash(int l, int r) {
    assert(l >= 0 && r >= l && r <= N);
    return ((h[r] - ((std::int64_t)h[l] * pw[r - l]) % M) + M) % M;
  }

  int hash(int r) { return hash(0, r); }

private:
  std::vector<int> h, pw;
  int N;
};
using str_hash1 = str_hash<239017, int(1e9 + 7)>;
using str_hash2 = str_hash<239017, int(1e9 + 9)>;

} // namespace strings
#endif
