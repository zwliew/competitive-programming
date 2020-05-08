#include <deque>
#include <utility>

struct MonoQueue {
  std::deque<std::pair<int, int>> q;

  void push(int val) {
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

  int min() { return q.front().first; }
}
