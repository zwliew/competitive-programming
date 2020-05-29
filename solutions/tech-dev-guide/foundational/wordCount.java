/**
 * https://techdevguide.withgoogle.com/paths/foundational/wordcount-problem-classic-algorithm-hard/#!
 *
 * The classic word-count algorithm: given an array of strings, return a
 * Map<String, Integer> with a key for each different string, with the value
 * the number of times that string appears in the array.
 *
 * wordCount(["a", "b", "a", "c", "b"]) → {"a": 2, "b": 2, "c": 1}
 * wordCount(["c", "b", "a"]) → {"a": 1, "b": 1, "c": 1}
 * wordCount(["c", "c", "c", "c"]) → {"c": 4}
 */
import java.util.HashMap;
import java.util.Map;

class Main {
    public static void main(String[] args) {
        System.out.println(wordCount(new String[] {"a", "b", "a", "c", "b"}));
        System.out.println(wordCount(new String[] {"c", "b", "a"}));
        System.out.println(wordCount(new String[] {"c", "c", "c", "c"}));
    }

    public static Map<String, Integer> wordCount(String[] strings) {
        final Map<String, Integer> result = new HashMap<>();
        for (String string : strings) {
            Integer value = result.get(string);
            result.put(string, value == null ? 1 : value + 1);
        }
        return result;
    }
}