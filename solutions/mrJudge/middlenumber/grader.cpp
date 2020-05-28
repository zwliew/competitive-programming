#include <cstdio>
#include <cstring>
#include "main.cc"
#include "middlenumber.h"

int main() {
  char c[8];
  int l, a, b;
  int* arr;
  bool inited = false;
  while (scanf(" %s", c) != EOF) {
    if (strcmp(c, "init") == 0) {
      if (inited) {
        fprintf(stderr, "Cannot call init() more than once!\n");
        return 1;
      }
      inited = true;
      scanf("%d", &l);
      arr = new int[l];
      for (int i = 0; i < l; ++i) {
        scanf("%d", arr + i);
      }
      printf("%d\n", init(arr, l));
    } else if (strcmp(c, "add") == 0) {
      if (!inited) {
        fprintf(stderr, "Cannot call add() before calling init()!\n");
        return 1;
      }
      scanf("%d", &a);
      printf("%d\n", add_number(a));
    } else if (strcmp(c, "remove") == 0) {
      if (!inited) {
        fprintf(stderr, "Cannot call remove() before calling init()!\n");
        return 1;
      }
      scanf("%d", &a);
      printf("%d\n", remove_number(a));
    } else if (strcmp(c, "change") == 0) {
      if (!inited) {
        fprintf(stderr, "Cannot call change() before calling init()!\n");
        return 1;
      }
      scanf("%d%d", &a, &b);
      printf("%d\n", change_number(a, b));
    } else {
      fprintf(stderr, "Unknown command \"%s\".\n", c);
      return 1;
    }
  }
  return 0;
}
