#include <iostream>
#include <string>

int main() {
  size_t N;
  std::cin >> N;

  size_t length = 0;
  size_t count = 0;

  std::string line;
  for (size_t i = 0; i < N; i++) {
    std::cin >> line;

    length += line.size();
    for (char c : line) {
      if (c == 'C' || c == 'c')
        count++;
    }
  }

  std::cout << static_cast<size_t>((count / static_cast<double>(length)) * 100)
            << "%";
}
