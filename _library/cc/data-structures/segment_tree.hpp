#include <algorithm>
#include <vector>

template <typename T> class segment_tree {
private:
  std::vector<T> t;
  int N;

  const T NEUTRAL = -1;
  T merge(T &x, T &y) const { return std::min(x, y); }

  void modify(int ti, T &x) { t[ti] = x; }

  void build(std::vector<T> &A, int ti, int tl, int tr) {
    assert(tl >= 0 && tr <= N);
    if (tl == tr - 1) {
      modify(ti, A[tl]);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(A, ti * 2 + 1, tl, tm);
    build(A, ti * 2 + 2, tm, tr);
    t[ti] = merge(t[ti * 2 + 1], t[ti * 2 + 2]);
  }

  void update(int i, T x, int ti, int tl, int tr) {
    assert(tl >= 0 && tr <= N);
    if (tl == tr - 1) {
      modify(ti, x);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i < tm) {
      update(i, x, ti * 2 + 1, tl, tm);
    } else {
      update(i, x, ti * 2 + 2, tm, tr);
    }
    t[ti] = merge(t[ti * 2 + 1], t[ti * 2 + 2]);
  }

  T query(int l, int r, int ti, int tl, int tr) {
    assert(tl >= 0 && tr <= N);
    if (l >= tr || r <= tl) {
      return NEUTRAL;
    }
    if (tl >= l && tr <= r) {
      return t[ti];
    }
    int tm = tl + (tr - tl) / 2;
    T a = query(l, r, ti * 2 + 1, tl, tm);
    T b = query(l, r, ti * 2 + 2, tm, tr);
    return merge(a, b);
  }

public:
  segment_tree(std::vector<T> &A) {
    N = A.size();
    t.resize(N * 4);

    build(A, 0, 0, N);
  }

  void update(int i, T x) { _update(i, x, 0, 0, N); }

  T query(int l, int r) { return query(l, r, 0, 0, N); }
};
