#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int32_t partition(std::vector<int32_t> &arr, const int32_t lo,
                  const int32_t hi) {
  const int32_t pivot = arr.at(((uint32_t)lo + (uint32_t)hi) >> 1);
  int32_t i = lo - 1;
  int32_t j = hi + 1;

  while (true) {
    while (arr.at(++i) < pivot)
      ;

    while (arr.at(--j) > pivot)
      ;

    if (i >= j)
      return j;

    std::swap(arr.at(i), arr.at(j));
  }
}

void qsort(std::vector<int32_t> &arr, const int32_t lo, const int32_t hi) {
  if (lo >= hi)
    return;

  const int32_t p = partition(arr, lo, hi);
  qsort(arr, lo, p);
  qsort(arr, p + 1, hi);
}

int main() {
  int32_t N;
  std::cin >> N;

  std::vector<int32_t> X(N);
  for (int32_t i = 0; i < N; i++) {
    std::cin >> X.at(i);
  }

  qsort(X, 0, N - 1);

  for (int32_t i = 0; i < N; i++) {
    std::cout << X.at(i) << '\n';
  }
}
