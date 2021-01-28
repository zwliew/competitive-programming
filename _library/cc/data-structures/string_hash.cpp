#include <string>
#include <vector>

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

  // r is 1 past the last index of the substring
  int compute(int l, int r) {
    return ((h[r] - ((int64_t)h[l] * pw[r - l]) % M) + M) % M;
  }
};
