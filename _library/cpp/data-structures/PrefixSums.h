#include <vector>

// For computing static range sums over a 1D array
template <typename T>
struct PrefixSums1D {
  std::vector<T> prefixSums;

  PrefixSums1D(const std::vector<T> &v) {
    prefixSum.emplace_back(0);
    std::partial_sum(v.begin(), v.end(), std::back_inserter(prefixSum));
  }

  T query(int l, int r) { return prefixSum[r + 1] - prefixSum[l]; }
};