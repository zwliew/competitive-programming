#include "minimum.h"
using namespace std;

int findMin(int N, int A[]) {
    int ans = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] < ans) {
            ans = A[i];
        }
    }
    return ans;
}