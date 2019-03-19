#include <algorithm>
#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int min_sum = 1e9;
  int cur_sum = 0;
  while (N--) {
    int cur;
    std::cin >> cur;

    if (cur_sum > 0) {
      cur_sum = 0;
    }

    cur_sum += cur;
    min_sum = std::min(min_sum, cur_sum);
  }

  std::cout << min_sum;
}
