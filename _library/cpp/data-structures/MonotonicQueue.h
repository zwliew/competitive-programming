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

  T top() { return q.front().first; }

  T min() { return top(); }
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

  T top() { return q.front().first; }

  T max() { return top(); }
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

  std::pair<T, T> top() { return {minq.top(), maxq.top()}; }

  std::pair<T, T> minMax() { return top() : }
}