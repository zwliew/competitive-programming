#include "memory.h"
#include "grader.h"

void play() {
  int a[25], b[25];
  for (int i = 0; i < 25; ++i) {
    a[i] = 0;
  }
  for (int i = 1; i <= 50; ++i) {
    int x = faceup(i);
    x -= 'A';
    if (a[x]) {
      b[x] = i;
    } else {
      a[x] = i;
    }
  }
  for (int i = 0; i < 25; ++i) {
    faceup(a[i]);
    faceup(b[i]);
  }
}
