#include <iostream>

int climbStairs(const int n) {
  int first = 1, second = 1;
  for (int i = 2; i <= n; i++) {
    int tmp = first + second;
    first = second;
    second = tmp;
  }
  return second;
}

int main() {
  int n;
  std::cin >> n;

  std::cout << climbStairs(n);
}
