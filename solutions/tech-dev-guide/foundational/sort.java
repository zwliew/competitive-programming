/**
 * https://techdevguide.withgoogle.com/paths/foundational/array-sort-problem-sorted-values
 *
 * Return an array that contains the sorted values from the input array
 * with duplicates removed.
 *
 * sort([]) → []
 * sort([1]) → [1]
 * sort([1, 1]) → [1]
 */
import java.util.ArrayList;
import java.util.Collections;

class Main {
    public static void main(String[] args) {
        System.out.println(sort(new int[] {}));
        System.out.println(sort(new int[] {1}));
        System.out.println(sort(new int[] {1, 1}));
    }

    static int[] sort(int[] a) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int el : a) {
            if (!list.contains(el)) {
                list.add(el);
            }
        }
        Collections.sort(list);
        int[] result = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i).intValue();
        }
        return result;
    }
}