#ifndef STR_HASH_CPP
#define STR_HASH_CPP

#include <array>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

// P = 31 or 9973 or 239017
// M = 1e9 + 9 or 1e9 + 7, 998244353
namespace strings {
constexpr int P = 239017;
constexpr int M1 = 1e9 + 7;
constexpr int M2 = 1e9 + 9;

template <int P, int M> class str_hash_pw {
public:
  str_hash_pw() {}

  str_hash_pw(const std::string &s) : N(s.size()) {
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

template <int P, int M> class str_hash {
public:
  str_hash() {}

  str_hash(const std::string &s, const int *_pw) : N(s.size()), pw(_pw) {
    h.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
      h[i] = ((std::int64_t)h[i - 1] * P + s[i - 1]) % M;
    }
  }

  // Returns the hash of the substring in the range [l, r)
  int hash(int l, int r) {
    assert(l >= 0 && r >= l && r <= N);
    return ((h[r] - ((std::int64_t)h[l] * *(pw + r - l)) % M) + M) % M;
  }

  int hash(int r) { return hash(0, r); }

private:
  const int *pw;
  std::vector<int> h;
  int N;
};

template <int P, int M> std::vector<int> gen_pow(int N) {
  std::vector<int> pw(N + 1);
  pw[0] = 1;
  for (int i = 1; i <= N; ++i) {
    pw[i] = ((std::int64_t)pw[i - 1] * P) % M;
  }
  return pw;
}

template <int P, int M, int N> std::array<int, N + 1> gen_pow() {
  std::array<int, N + 1> pw;
  pw[0] = 1;
  for (int i = 1; i <= N; ++i) {
    pw[i] = ((std::int64_t)pw[i - 1] * P) % M;
  }
  return pw;
}

using str_hash_pw1 = str_hash_pw<P, M1>;
using str_hash_pw2 = str_hash_pw<P, M2>;
using str_hash1 = str_hash<P, M1>;
using str_hash2 = str_hash<P, M2>;

} // namespace strings
#endif
