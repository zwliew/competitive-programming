#include "grading.h"
using namespace std;

string gradeMin(int N, int A[]) {
  int ans = A[0];
  for (int i = 1; i < N; i++) {
      if (A[i] < ans) {
          ans = A[i];
      }
  }

  startTime();
  int gradAns = findMin(N, A);
  int ms = stopTime();

  if (ms > 500) {
    return "Time Limit Exceeded";
  } else {
    if (gradAns == ans) {
      return "Accepted";
    } else {
      return "Wrong Answer";
    }
  }
}