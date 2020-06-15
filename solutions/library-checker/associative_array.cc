/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include <debug.h>
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <typename K, typename V>
using HashMap = gp_hash_table<K, V, custom_hash>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int q;
  cin >> q;
  HashMap<long long, long long> m;
  while (q--) {
    int x;
    long long a, b;
    cin >> x >> a;
    if (x) {
      cout << m[a] << '\n';
    } else {
      cin >> b;
      m[a] = b;
    }
  }
}
