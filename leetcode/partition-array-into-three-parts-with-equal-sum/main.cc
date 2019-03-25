#include <vector>
#include <iostream>

bool canThreePartsEqualSum(std::vector<int> &A) {
  int32_t sum = 0;
  for (int a : A)
    sum += a;

  if (sum % 3 != 0)
    return false;

  const int32_t goal = sum / 3;
  bool first_found = false;
  int32_t cur_sum = 0;
  for (uint32_t i = 0; i < A.size(); i++) {
    cur_sum += A.at(i);
    if (cur_sum == goal && !first_found) {
      first_found = true;
    } else if (cur_sum == goal * 2 && first_found) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<int> v = {6,1,1,13,-1,0,-10,20};
  std::cout << canThreePartsEqualSum(v);
}
