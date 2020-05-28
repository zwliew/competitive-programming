#include <iostream>
#include <vector>

// Dynamic programming without binary search runs in O(n^2) time,
// where n  denotes the length of the input string
int main() {
  int N;
  std::cin >> N;

  std::vector<int> seq = std::vector<int>(N);
  for (int i = 0; i < N; i++) {
    std::cin >> seq[i];
  }

  std::vector<int> lis = std::vector<int>(N);

  int longest = lis[0] = 1;
  for (int i = 1; i < N; i++) {
    int prev_longest = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (seq[i] > seq[j]) {
        prev_longest = std::max(lis[j], prev_longest);
      }
    }
    lis[i] = prev_longest + 1;
    longest = std::max(lis[i], longest);
  }

  std::cout << longest;
}
