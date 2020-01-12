/**
 * Problem:
 * https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
 *
 * Iterative complete search solution
 * Time complexity: O(n * log(n))
 * Space complexity: O(1)
 *
 * The solution is accepted as n is at most 10^4.
 */
class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    vector<int> r;
    for (int a = 1; a <= (n >> 1); ++a) {
      int tmp = a;
      bool zero = false;
      while (tmp) {
        if (!(tmp % 10)) {
          zero = true;
          break;
        }
        tmp /= 10;
      }

      if (zero) continue;

      int b = n - a;
      zero = false;
      tmp = b;
      while (tmp) {
        if (!(tmp % 10)) {
          zero = true;
          break;
        }
        tmp /= 10;
      }

      if (zero) continue;

      r = {a, b};
      return r;
    }

    return r;
  }
};