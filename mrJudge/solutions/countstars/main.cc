#include <iostream>

int main() {
  uint32_t H, W;
  std::cin >> H >> W;

  uint32_t count = 0;

  for (uint32_t i = 0; i < H * W; i++) {
    uint8_t in;
    std::cin >> in;

    if (in == '*') {
      count++;
    }
  }

  std::cout << count;
}
