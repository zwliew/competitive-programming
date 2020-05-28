#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdint>

std::vector<int> twoSum(const std::vector<int>& nums, const int &target) {
  std::unordered_map<int32_t, uint32_t> m;
  std::vector<int> ret;
  for (uint32_t i = 0; i < nums.size(); i++) {
    const auto val = m.find(nums.at(i));
    if (val == m.end()) {
      m.emplace(target - nums.at(i), i);
    } else {
      ret.emplace_back(val->second);
      ret.emplace_back(i);
      return ret;
    }
  }
  return ret;
}

int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  const auto res = twoSum(nums, 9);
  std::cout << res.at(0) << ' ' << res.at(1);
}
