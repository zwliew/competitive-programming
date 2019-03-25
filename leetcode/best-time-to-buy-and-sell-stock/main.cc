#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(std::vector<int> &prices) {
  int min_price = UINT_MAX;
  int max_profit = 0;
  for (int price : prices) {
    min_price = std::min(min_price, price);
    max_profit = std::max(max_profit, price - min_price);
  }
  return max_profit;
}

int main() {

}
