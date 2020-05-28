#include <array>
#include <iostream>
#include <string>
#include <vector>

unsigned long minDistance(std::string word1, std::string word2) {
  std::array<unsigned long, 2> len = {word1.length(), word2.length()};
  std::vector<std::vector<int>> memo(len[0] + 1,
                                     std::vector<int>(len[1] + 1, 0));

  for (int i = 0; i <= len[0]; i++) {
    memo[i][0] = i;
  }

  for (int i = 0; i <= len[1]; i++) {
    memo[0][i] = i;
  }

  for (int i = 1; i <= len[0]; i++) {
    for (int j = 1; j <= len[1]; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        memo[i][j] = memo[i - 1][j - 1];
      } else {
        memo[i][j] = std::min(std::min(memo[i - 1][j], memo[i][j - 1]),
                              memo[i - 1][j - 1]) +
                     1;
      }
    }
  }

  return memo[len[0]][len[1]];
}

int main() {
  std::string word1, word2;
  std::cin >> word1 >> word2;

  std::cout << minDistance(word1, word2);
}
