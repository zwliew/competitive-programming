#include <vector>
#include "reverse.h"

std::vector<long long> reverse(std::vector<long long> a) {
  for (int i = 0; i < a.size() / 2; ++i) {
    a[i] ^= a[a.size() - 1 - i];
    a[a.size() - 1 - i] ^= a[i];
    a[i] ^= a[a.size() - 1 - i];
  }
  return a;
}
