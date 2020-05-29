/**
 * https://techdevguide.withgoogle.com/paths/foundational/maxspan-problem-return-largest-span-array/#!
 *
 * Consider the leftmost and righmost appearances of some value in an array.
 * We'll say that the "span" is the number of elements between the two inclusive.
 * A single value has a span of 1.
 * Returns the largest span found in the given array.
 * (Efficiency is not a priority.)
 *
 * maxSpan([1, 2, 1, 1, 3]) → 4
 * maxSpan([1, 4, 2, 1, 4, 1, 4]) → 6
 * maxSpan([1, 4, 2, 1, 4, 4, 4]) → 6
 */
public int maxSpan(int[] nums) {
  final Map<Integer, ArrayList<Integer>> map = new HashMap<>();
  for (int i = 0; i < nums.length; i++) {
    if (!map.containsKey(nums[i])) {
        map.put(nums[i], new ArrayList<Integer>());
    }
    map.get(nums[i]).add(i);
  }
  int max = 0;
  for (Map.Entry<Integer, ArrayList<Integer>> pair : map.entrySet()) {
    ArrayList<Integer> v = pair.getValue();
    Collections.sort(v);
    int span = v.get(v.size() - 1) - v.get(0) + 1;
    if (span > max) {
      max = span;
    }
  }
  return max;
}
