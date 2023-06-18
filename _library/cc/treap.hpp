#ifndef TREAP_HPP
#define TREAP_HPP

#include <chrono>
#include <cstdint>
#include <random>
#include <utility>

namespace treap {
namespace internal {
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
}

template <class T> struct treap {
public:
  bool flipped;
  std::int64_t sum;
  int size;
  T val;
  int prio;
  treap *l, *r;
  treap(T val)
      : flipped(false), sum(val), size(1), val(val), prio(internal::rng()),
        l(nullptr), r(nullptr) {}

  void update() {
    size = get_size(l) + get_size(r) + 1;
    sum = get_sum(l) + get_sum(r) + val;
  }

  void push() {
    if (!flipped)
      return;
    flipped = false;
    std::swap(l, r);
    if (l)
      l->flipped = !l->flipped;
    if (r)
      r->flipped = !r->flipped;
  }

  static int get_val(treap *t) { return t ? t->val : 0; }
  static int get_size(treap *t) { return t ? t->size : 0; }
  static std::int64_t get_sum(treap *t) { return t ? t->sum : 0; }
};

template <class T> treap<T> *merge(treap<T> *l, treap<T> *r) {
  if (!l)
    return r;
  if (!r)
    return l;
  l->push();
  r->push();
  treap<T> *res;
  if (l->prio > r->prio) {
    l->r = merge(l->r, r);
    res = l;
  } else {
    r->l = merge(l, r->l);
    res = r;
  }
  res->update();
  return res;
}

template <class T> std::pair<treap<T> *, treap<T> *> split(treap<T> *t, int x) {
  if (!t)
    return {nullptr, nullptr};
  t->push();
  if (t->val >= x) {
    auto p = split(t->l, x);
    t->l = p.second;
    t->update();
    return {p.first, t};
  } else {
    auto p = split(t->r, x);
    t->r = p.first;
    t->update();
    return {t, p.second};
  }
}

template <class T>
std::pair<treap<T> *, treap<T> *> split_sz(treap<T> *t, int x) {
  if (!t)
    return {nullptr, nullptr};
  t->push();
  if (treap<T>::get_size(t->l) >= x) {
    auto p = split_sz(t->l, x);
    t->l = p.second;
    t->update();
    return {p.first, t};
  } else {
    auto p = split_sz(t->r, x - treap<T>::get_size(t->l) - 1);
    t->r = p.first;
    t->update();
    return {t, p.second};
  }
}

template <class T> treap<T> *insert(treap<T> *t, int x) {
  auto a = split(t, x);
  auto b = split(a.second, x + 1);
  auto *res = new treap<T>(x);
  res = merge(res, b.second);
  res = merge(a.first, res);
  return res;
}

template <class T> treap<T> *erase(treap<T> *t, int x) {
  auto a = split(t, x);
  auto b = split(a.second, x + 1);
  return merge(a.first, b.second);
}

template <class T> std::vector<T> tour(treap<T> *t) {
  if (!t)
    return {};
  t->push();
  auto res = tour(t->l);
  res.push_back(t->val);
  auto tmp = tour(t->r);
  res.insert(res.end(), tmp.begin(), tmp.end());
  return res;
}

} // namespace treap
#endif // TREAP_HPP
