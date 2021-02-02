#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

#include <ext/pb_ds/assoc_container.hpp>

struct splitmix64_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

void input(int& number) {
  bool neg = false;
  int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    neg = true;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    number = number * 10 + c - 48;
  }
  if (neg) {
    number *= -1;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  input(T);
  for (int ti = 1; ti <= T; ++ti) {
    int N;
    input(N);
    hash_map<int, int> lastUsed;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int M;
      input(M);
      vector<int> used(M);
      int time = 0;
      for (int j = 0; j < M - 1; ++j) {
        input(used[j]);
        time = max(time, lastUsed[used[j]]);
      }
      ++time;
      input(used.back());
      lastUsed[used.back()] = time;
      ans = max(ans, time);
    }
    printf("%d %d\n", ti, ans);
  }
}
