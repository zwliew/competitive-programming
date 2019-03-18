#include <iostream>
#include <string>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  int shortest_idx = -1;
  int shortest_len = -1;
  std::vector<std::string> strs(N);
  for (int i = 0; i < N; i++) {
    std::string str;
    std::cin >> str;
    strs.at(i) = str;
    int len = str.length();
    if (shortest_idx == -1 || len < shortest_len) {
      shortest_idx = i;
      shortest_len = len;
    }
  }

  int len = 0;
  for (auto c : strs.at(shortest_idx)) {
    bool equals = true;
    for (auto str : strs) {
      if (str.at(len) != c) {
        equals = false;
        break;
      }
    }
    if (!equals)
      break;

    len++;
  }

  std::cout << strs.at(shortest_idx).substr(0, len);
}
