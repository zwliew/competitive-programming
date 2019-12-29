#include "swapcup.h"
using namespace std;

unsigned int cur = 2;

void startGame() {

}

void swap(int A, int B) {
  if (A == cur) {
    cur = B;
  } else if (B == cur) {
    cur = A;
  }
}

int getAnswer() {
  return cur;
}
