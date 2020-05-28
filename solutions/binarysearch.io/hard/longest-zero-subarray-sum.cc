#include <bits/stdc++.h>

#include "solution.hpp"
using namespace std;

int Solution::solve(vector<int>& nums) {
  unordered_map<int, int> hm = {{0, -1}};
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == 1) {
      ++cur;
    } else {
      --cur;
    }
    auto it = hm.find(cur);
    if (it != hm.end()) {
      ans = max(ans, i - it->second);
    } else {
      hm[cur] = i;
    }
  }
  return ans;
};
