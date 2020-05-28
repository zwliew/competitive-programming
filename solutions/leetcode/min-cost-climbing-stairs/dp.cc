#include <algorithm>
#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int> &cost) {
  cost.emplace_back(0); // last step has 0 cost

  int first_sum = cost.at(0);
  int second_sum = cost.at(1);
  for (int i = 2; i < cost.size(); i++) {
    int cur_sum = std::min(first_sum, second_sum) + cost.at(i);
    first_sum = second_sum;
    second_sum = cur_sum;
  }
  return second_sum;
}

int main() {
  std::vector<int> cost;
  int tmp;
  std::cin >> tmp;
  while (tmp != -1) {
    cost.emplace_back(tmp);
    std::cin >> tmp;
  }
  std::cout << minCostClimbingStairs(cost);
}
