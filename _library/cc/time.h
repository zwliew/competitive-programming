#include <chrono>
#include <iostream>

void time() {
  auto start = std::chrono::steady_clock::now();

  auto end = std::chrono::steady_clock::now();
  std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << "ms\n";
}