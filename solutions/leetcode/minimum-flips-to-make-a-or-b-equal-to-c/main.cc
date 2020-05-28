/**
 * Problem:
 * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 *
 * Time complexity: O(1) // bounded by the maximum number of bits in each
 * integer input, which is 31. Space complexity: O(1)
 *
 * Accepted as maximum input is 10^9.
 */
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int maxv = 0;
    maxv = max(a, max(b, c));
    int cnt = 0;
    for (int i = 0; (maxv >> i); ++i) {
      bool at = a & (1 << i);
      bool bt = b & (1 << i);
      bool ct = c & (1 << i);
      if ((at || bt) && !ct) {
        cnt += at + bt;
      } else if ((!at && !bt) && ct) {
        ++cnt;
      }
    }
    return cnt;
  }
};