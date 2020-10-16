#include "cluedo.h"
#include "grader.h"

void Solve() {
  int i = 1, j = 1, k = 1;
  int idx;
  while (idx = Theory(i, j, k)) {
    if (idx == 1) {
      ++i;
    } else if (idx == 2) {
      ++j;
    } else {
      ++k;
    }
  }
}
