#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(const std::pair<int, int> &i, const std::pair<int, int>&j) {
  return i.first > j.first;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> inc(n);
  std::vector<int> prc(n);
  for (int i = 0; i < n; i++) {
    std::cin >> prc.at(i);
  }
  for (int i = 0; i < n; i++) {
    std::cin >> inc.at(i);
  }

  std::vector<std::pair<int, int>> inc_to_prc(n);
  for (int i = 0; i < n; i++) {
    inc_to_prc.at(i) = std::make_pair(inc.at(i), prc.at(i));
  }

  std::sort(inc_to_prc.begin(), inc_to_prc.end(), compare);

  int total = 0;
  for (int i = 0; i < n; i++) {
    auto pair = inc_to_prc.at(i);
    total += std::get<0>(pair) * i + std::get<1>(pair);
  }

  std::cout << total;
}