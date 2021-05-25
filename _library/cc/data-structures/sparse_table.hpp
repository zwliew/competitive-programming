#include <numeric>
#include <vector>

template <typename T> class sparse_table {
private:
  std::vector<std::vector<T>> t;
  int H;

  const T NEUTRAL = INT_MAX;
  T merge(T &a, T &b) { return std::min(a, b); }

public:
  sparse_table(std::vector<T> &A) {
    int N = A.size();
    H = std::ceil(std::log2(N));
    t.assign(H + 1, std::vector<T>(N));
    for (int i = 0; i < N; ++i) {
      t[0][i] = A[i];
    }
    for (int i = 1; i <= H; ++i) {
      for (int j = 0; j + (1 << i) - 1 <= N; ++j) {
        t[i][j] = merge(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  // Exclusive range: [l, r)
  T query(int l, int r) {
    T res = NEUTRAL;
    for (int i = H; i >= 0; --i) {
      if ((1 << i) <= r - l) {
        res = merge(res, t[i][l]);
        l += 1 << i;
      }
    }
    return res;
  }
};
