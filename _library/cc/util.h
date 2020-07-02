#define s64 long long

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

template <typename T>
inline s64 ndigits(T x, T b) {
  s64 r = 0;
  while (x) {
    x /= b;
    ++r;
  }
  return r;
}