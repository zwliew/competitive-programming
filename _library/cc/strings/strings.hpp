#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>
#include <vector>

namespace strings {
// Returns an array of length s.size() such that
// s[i] is the length of the LCP of s[0..n) and s[i..n).
template <class T> std::vector<int> z_algorithm(const std::vector<T> &s) {
  int n = int(s.size());
  if (n == 0)
    return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int &k = z[i];
    k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k])
      k++;
    if (j + z[j] < i + z[i])
      j = i;
  }
  z[0] = n;
  return z;
}

std::vector<int> z_algorithm(const std::string &s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}

std::vector<int> prefix_function(const std::string &s) {
  int n = int(s.size());
  std::vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      ++j;
    pi[i] = j;
  }
  return pi;
}

/**
 * manacher(S): return the maximum palindromic substring of S centered at each
 * point
 *
 * Input: string (or vector) of length N (no restrictions on character-set)
 * Output: vector res of length 2*N+1
 *   For any 0 <= i <= 2*N:
 *   * i % 2 == res[i] % 2
 *   * the half-open substring S[(i-res[i])/2, (i+res[i])/2) is a palindrome of
 * length res[i]
 *   * For odd palindromes, take odd i, and vice versa
 */
std::vector<int> manacher(const std::string &s) {
  int n = int(s.size());
  std::vector<int> res(2 * n + 1);
  for (int i = 1, j = -1, r = 0; i < 2 * n; i++, j--) {
    if (i > r) {
      r = i + 1, res[i] = 1;
    } else {
      res[i] = res[j];
    }
    if (i + res[i] >= r) {
      int b = r >> 1, a = i - b;
      while (a > 0 && b < n && s[a - 1] == s[b]) {
        a--, b++;
      }
      res[i] = b - a, j = i, r = b << 1;
    }
  }
  return res;
}

} // namespace strings

#endif
