#include <iostream>

int main() {
  int N;
  std::cin >> N;

  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= N; x++) {
      if (x >= y) {
        std::cout << y;
      } else {
        std::cout << x;
      }
    }

    for (int x = N; x >= 1; x--) {
      if (x >= y) {
        std::cout << y;
      } else {
        std::cout << x;
      }
    }
    std::cout << "\n";
  }

  for (int y = N; y >= 1; y--) {
    for (int x = 1; x <= N; x++) {
      if (x >= y) {
        std::cout << y;
      } else {
        std::cout << x;
      }
    }

    for (int x = N; x >= 1; x--) {
      if (x >= y) {
        std::cout << y;
      } else {
        std::cout << x;
      }
    }
    std::cout << "\n";
  }
}
