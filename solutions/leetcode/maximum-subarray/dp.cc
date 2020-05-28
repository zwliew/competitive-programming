#include <algorithm>
#include <iostream>
#include <vector>

int maxSubArray(std::vector<int> &nums) {
  int max_sum, prev_sum;
  max_sum = prev_sum = nums.at(0);
  for (int i = 1; i < nums.size(); i++) {
    prev_sum = std::max(prev_sum + nums.at(i), nums.at(i));
    max_sum = std::max(prev_sum, max_sum);
  }
  return max_sum;
}
