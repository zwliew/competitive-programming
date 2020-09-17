#include <numeric>
#include <vector>

// Sqrt decomposition based on
// https://cp-algorithms.com/data_structures/sqrt_decomposition.html This
// template computes the sum of a range.
template <class T>
struct SqrtDecomposition {
  std::vector<T> comp, arr;
  int len;

  const T INITIAL_VAL = 0;

  T compute(T a, T b) { return a + b; }

  SqrtDecomposition(std::vector<T>& a) : arr(a) {
    len = (int)std::sqrt(a.size()) + 1;
    comp.assign(len, INITIAL_VAL);
    for (int i = 0; i < a.size(); ++i) {
      int blockIdx = i / len;
      comp[blockIdx] = compute(comp[blockIdx], a[i]);
    }
  }

  T query(int l, int r) {
    T res = INITIAL_VAL;
    for (int i = l; i <= r;) {
      if (i % len == 0 && i + len - 1 <= r) {
        res = compute(res, comp[i / len]);
        i += len;
      } else {
        res = compute(res, arr[i]);
        ++i;
      }
    }
    return res;
  }

  void update(int idx, T x) {
    arr[idx] = x;
    int blockIdx = idx / len;
    comp[blockIdx] = INITIAL_VAL;
    int start = blockIdx * len;
    for (int i = 0; i < len && start + i < arr.size(); ++i) {
      comp[blockIdx] = compute(comp[blockIdx], arr[start + i]);
    }
  }
};