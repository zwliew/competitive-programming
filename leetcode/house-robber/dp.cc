#include <algorithm>
#include <iostream>
#include <vector>

int rob(std::vector<int> &nums) {
  int first, second;
  first = second = 0;
  for (auto num : nums) {
    int tmp = first;
    first = second;
    second = std::max(tmp + num, second);
  }
  return second;
}

int main() {
  std::vector<int> nums;
  int tmp;
  std::cin >> tmp;
  while (tmp != -1) {
    nums.emplace_back(tmp);
    std::cin >> tmp;
  }
  std::cout << rob(nums);
}
