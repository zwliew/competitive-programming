#include <deque>
#include <utility>

template <typename T>
struct MonoQueue {
  std::deque<std::pair<T, int>> q;

  void push(T val) {
    int count = 1;
    while (q.size() && q.back().first >= val) {
      count += q.back().second;
      q.pop_back();
    }
    q.emplace_back(val, count);
  }

  void pop() {
    q.front().second--;
    if (q.front().second == 0) {
      q.pop_front();
    }
  }

  T min() { return q.front().first; }
};
