#include <deque>
#include <utility>

// For computing minimums over sliding windows
// Similar to using a BST but with linear time complexity
template <typename T>
struct MinMonotonicQueue {
  std::deque<std::pair<T, int>> q;

  void push(T x) {
    int cnt = 1;
    while (q.size() && q.back().first > x) {
      cnt += q.back().second;
      q.pop_back();
    }
    q.emplace_back(x, cnt);
  }

  T pop() {
    T res = top();
    --q.front().second;
    if (!q.front().second) {
      q.pop_front();
    }
    return res;
  }

  T top() const { return q.front().first; }

  T min() const { return top(); }
};

// For computing maximums over sliding windows
// Similar to using a BST but with linear time complexity
template <typename T>
struct MaxMonotonicQueue {
  std::deque<std::pair<T, int>> q;

  void push(T x) {
    int cnt = 1;
    while (q.size() && q.back().first < x) {
      cnt += q.back().second;
      q.pop_back();
    }
    q.emplace_back(x, cnt);
  }

  T pop() {
    T res = top();
    --q.front().second;
    if (!q.front().second) {
      q.pop_front();
    }
    return res;
  }

  T top() const { return q.front().first; }

  T max() const { return top(); }
};

template <typename T>
struct MinMaxMonotonicQueue {
  MinMonotonicQueue<T> minq;
  MaxMonotonicQueue<T> maxq;

  void push(T x) {
    minq.push(x);
    maxq.push(x);
  }

  std::pair<T, T> pop() { return {minq.pop(), maxq.pop()}; }

  std::pair<T, T> top() const { return {minq.top(), maxq.top()}; }

  std::pair<T, T> minMax() const { return top(); }
};
