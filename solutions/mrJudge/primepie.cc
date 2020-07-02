#include "primepie.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000000;
bitset<MAXN + 1> isPrime;
long long int amountEaten(int N) {
  if (N == 1) {
    return 2;
  }

  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 4; i <= MAXN; i += 2) {
    isPrime[i] = false;
  }
  for (int i = 3; i * i <= MAXN; i += 2) {
    if (!isPrime[i])
      continue;
    for (int j = i * i; j <= MAXN; j += i) {
      isPrime[j] = false;
    }
  }

  int cnt = 1;
  int64_t sum = 2;
  for (int i = 3; i <= MAXN && cnt < N; i += 2) {
    if (isPrime[i]) {
      ++cnt;
      sum += i;
    }
    if (cnt == N)
      return sum;
  }
  return -1;
}