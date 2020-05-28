#include <iostream>
#include <string>

int main() {
  size_t H, W;
  std::cin >> H >> W;

  uint16_t o = 0, n = 0;

  std::string line;
  std::cin >> line;
  for (size_t i = 1; i < H - 1; i++) {
    std::cin >> line;

    for (size_t j = 1; j < W - 1; j++) {
      uint8_t c = line.at(j);
      if (c == 'O') {
        o++;
      } else if (c == 'N') {
        n++;
      }
    }
  }

  std::cout << o << ' ' << n << '\n';
}
