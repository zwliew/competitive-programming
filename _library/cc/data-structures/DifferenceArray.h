#include <iterator>
#include <vector>

// For offline range updates and point queries in O(n) time.
template <typename T>
struct DifferenceArray {
  std::vector<T> diff, accumulated;

  DifferenceArray(size_t n) : diff(n + 1) {}

  bool update(int l, int r, T val) {
    if (accumulated.size()) return false;
    diff[l] += val;
    diff[r + 1] -= val;
    return true;
  }

  // Only accumulate once.
  std::vector<T> accumulate() {
    if (accumulated.empty()) {
      partial_sum(diff.begin(), diff.end() - 1,
                  std::back_inserter(accumulated));
    }
    return accumulated;
  }

  T query(int idx) { return accumulated[idx]; }
};
