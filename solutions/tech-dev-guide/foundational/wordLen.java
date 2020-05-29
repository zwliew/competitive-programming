/**
 * https://techdevguide.withgoogle.com/paths/foundational/wordlen-problems-array-strings-medium/#!
 *
 * Given an array of strings, return a Map<String, Integer> containing a key
 * for every different string in the array, and the value is that string's length.
 *
 * wordLen(["a", "bb", "a", "bb"]) → {"bb": 2, "a": 1}
 * wordLen(["this", "and", "that", "and"]) → {"that": 4, "and": 3, "this": 4}
 * wordLen(["code", "code", "code", "bug"]) → {"code": 4, "bug": 3}
 */
import java.util.HashMap;
import java.util.Map;

class Main {
    public static void main(String[] args) {
        System.out.println(wordLen(new String[] {"a", "bb", "a", "bb"}));
        System.out.println(wordLen(new String[] {"this", "and", "that", "and"}));
        System.out.println(wordLen(new String[] {"code", "code", "code", "bug"}));
    }

    public static Map<String, Integer> wordLen(String[] strings) {
        final Map<String, Integer> result = new HashMap<>();
        for (String string : strings) {
            result.put(string, string.length());
        }
        return result;
    }
}