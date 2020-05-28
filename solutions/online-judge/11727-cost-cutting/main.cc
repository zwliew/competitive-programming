// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2827

#include <algorithm>
#include <iostream>

int main() {
  unsigned int T;
  std::cin >> T;

  for (unsigned int i = 1; i <= T; i++) {
    unsigned int x[3];
    std::cin >> x[0] >> x[1] >> x[2];

    std::sort(x, x + 3);
    std::cout << "Case " << i << ": " << x[1] << '\n';
  }
}
