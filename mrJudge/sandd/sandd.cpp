#include "sandd.h"
int getPrice(int P) {
  int lo = 0;
  int hi = P;
  while (lo <= hi) {
    int m = lo + (hi - lo) / 2;
    long long s = supply(m);
    long long d = demand(m);
    if (s == d) {
      return m;
    }
    if (s < d) {
      lo = m + 1;
    } else {
      hi = m - 1;
    }
  }
  return lo;
}