#include <deque>
#include <functional>

template <class T, class Compare = std::less<T>>
class monotonic_queue {
 private:
  std::deque<std::pair<T, int>> q;
  const Compare cmp = Compare();

 public:
  void push(const T val) {
    int cnt = 1;
    while (q.size() && cmp(q.back().first, val)) {
      cnt += q.back().second;
      q.pop_back();
    }
    q.emplace_back(val, cnt);
  }

  void pop() {
    --q.front().second;
    if (!q.front().second) {
      q.pop_front();
    }
  }

  T top() const { return q.front().first; }
};
