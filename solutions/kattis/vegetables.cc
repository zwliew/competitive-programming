#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

struct Veg {
  int64_t length;
  int64_t pieces;
  Veg(int _length) : length(_length), pieces(1) {}
  Veg(int _length, int _pieces) : length(_length), pieces(_pieces) {}
  bool operator<(const Veg& other) const {
    int64_t f = length * other.pieces;
    int64_t s = other.length * pieces;
    return f < s;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  double T;
  int N;
  cin >> T >> N;
  multiset<Veg> vegs;
  for (int i = 0; i < N; ++i) {
    int w;
    cin >> w;
    vegs.emplace(w);
  }

  int ans = 0;
  while (vegs.begin()->length * vegs.rbegin()->pieces <
         T * vegs.rbegin()->length * vegs.begin()->pieces) {
    Veg u = *vegs.rbegin();
    vegs.erase(prev(vegs.end()));
    vegs.emplace(u.length, u.pieces + 1);
    ++ans;
  }
  cout << ans;
}
