#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    std::cin >> prices.at(i);
  }

  std::sort(prices.begin(), prices.end());

  int sets = prices.size() / 4;
  int total = 0;
  int cur_cnt = 0;
  for (int i = prices.size() - 1; i >= 0; i--) {
    if (!sets) {
      total += prices.at(i);
    } else {
      cur_cnt = (cur_cnt + 1) % 4;
      if (cur_cnt) {
        total += prices.at(i);
      } else {
        sets--;
      }
    }
  }

  std::cout << total;
}
