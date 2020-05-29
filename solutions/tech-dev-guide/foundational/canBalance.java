/**
 * https://techdevguide.withgoogle.com/paths/foundational/canbalance-problem-arrays-non-empty/
 *
 * Given a non-empty array, return true if there is a place to split the array
 * so that the sum of the numbers on one side is equal to the sum of the numbers
 * on the other side.
 *
 * canBalance([1, 1, 1, 2, 1]) → true
 * canBalance([2, 1, 1, 2, 1]) → false
 * canBalance([10, 10]) → true
 */
class Main {
    public static void main(String[] args) {
        System.out.println(canBalance(new int[] {1,1,1,2,1}));
        System.out.println(canBalance(new int[] {2,1,1,2,1}));
        System.out.println(canBalance(new int[] {10,10}));
     }

    public static boolean canBalance(int[] nums) {
        int m = 0;
        int leftSum = sum(nums, 0, m);
        int rightSum = sum(nums, m, nums.length);
        int prevShiftRight = 0;
        while (leftSum != rightSum && m <= nums.length && m >= 0) {
            int curShiftRight = 0;
            if (leftSum > rightSum) {
                m--;
                curShiftRight = -1;
            } else if (leftSum < rightSum) {
                m++;
                curShiftRight = 1;
            }
            if (prevShiftRight + curShiftRight == 0) {
                return false;
            }
            prevShiftRight = curShiftRight;
            leftSum = sum(nums, 0, m);
            rightSum = sum(nums, m, nums.length);
        }
        return leftSum == rightSum;
    }

    public static int sum(int[] nums, int lo, int hi) {
        int sum = 0;
        for (int i = lo; i < hi; i++) {
            sum += nums[i];
        }
        return sum;
    }
}