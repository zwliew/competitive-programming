#include <iostream>

int main() {
  std::string line;
  std::getline(std::cin, line);

  int count = 0;
  bool is_word = false;
  for (auto c : line) {
    if (!is_word && std::isalnum(c)) {
      is_word = true;
      count++;
    } else if (is_word && !std::isalnum(c)) {
      is_word = false;
    }
  }

  std::cout << count;
}
