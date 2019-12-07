#include <algorithm>
#include <iostream>
#include <vector>

// Dynamic programming with binary search runs in O(n^2) time,
// where n  denotes the length of the input string
int main() {
  int N;
  std::cin >> N;

  std::vector<int> seq = std::vector<int>(N);
  for (int i = 0; i < N; i++) {
    std::cin >> seq[i];
  }

  int max = 0;
  std::vector<int> lis;
  for (int num : seq) {
    auto it = std::lower_bound(lis.begin(), lis.end(), num);
    const int idx = it - lis.begin();
    if (it == lis.end()) {
      lis.push_back(num);
    } else {
      *it = num;
    }
    if (idx == max) {
      max++;
    }
  }

  std::cout << max;
}
