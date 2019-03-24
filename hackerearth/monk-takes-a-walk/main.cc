#include <iostream>
#include <string>

int main() {
  uint32_t T;
  std::cin >> T;

  for (uint32_t i = 0; i < T; i++) {
    uint32_t count = 0;
    std::string s;
    std::cin >> s;

    for (auto c : s) {
      c = std::tolower(c);
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        count++;
    }

    std::cout << count << '\n';
  }
}
