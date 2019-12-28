#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, l) for (s32 i = j; i < k; i += l)
#define REP(i, j) FOR(i, 0, j, 1)
#define ALL(x) x.begin(), x.end()
#define MEAN(a, b) min(a, b) + (abs(b - a) / 2)
#define FASTIO()    \
  cin.tie(nullptr); \
  ios::sync_with_stdio(false);

typedef int64_t s64;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint32_t u32;
typedef float f32;
typedef double f64;
typedef pair<s32, s32> PII;
typedef vector<s32> VI;
typedef vector<PII> VPII;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

int main() {
  // Don't collapse the block
  FASTIO();

  s32 n, h;
  cin >> n >> h;

  VI m(h, 0);
  multiset<s32, greater<int>> s;
  while (n--) {
    s32 a, b;
    cin >> a >> b;

    b %= h;

    auto it = s.find(m[b]);
    if (it != s.end()) {
      s.erase(it);
    }
    if (a) {
      ++m[b];
    } else {
      --m[b];
    }
    s.emplace(m[b]);

    cout << *s.begin() << '\n';
  }
}