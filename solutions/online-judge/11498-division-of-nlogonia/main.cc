// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2493&mosmsg=Submission+received+with+ID+23365518

#include <iostream>

int main() {
  unsigned int K;
  while (std::cin >> K && K) {
    int N, M;
    std::cin >> N >> M;
    for (unsigned int i = 0; i < K; i++) {
      int X, Y;
      std::cin >> X >> Y;

      if (X == N || Y == M) {
        std::cout << "divisa\n";
        continue;
      }

      if (X > N) {
        if (Y > M) {
          std::cout << "NE\n";
        } else {
          std::cout << "SE\n";
        }
      } else {
        if (Y > M) {
          std::cout << "NO\n";
        } else {
          std::cout << "SO\n";
        }
      }
    }
  }
}
