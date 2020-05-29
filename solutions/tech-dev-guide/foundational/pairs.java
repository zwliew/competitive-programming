/**
 * https://techdevguide.withgoogle.com/paths/foundational/pairs-problem-classic-algorithm-hard/#!
 *
 * Given an array of non-empty strings, create and return a Map<String, String>
 * as follows: for each string add its first character as a key with its last
 * character as the value.
 *
 * pairs(["code", "bug"]) → {"b": "g", "c": "e"}
 * pairs(["man", "moon", "main"]) → {"m": "n"}
 * pairs(["man", "moon", "good", "night"]) → {"g": "d", "m": "n", "n": "t"}
 */
import java.util.HashMap;
import java.util.Map;

class Main {
    public static void main(String[] args) {
        System.out.println(pairs(new String[] {"code", "bug"}));
        System.out.println(pairs(new String[] {"man", "moon", "main"}));
        System.out.println(pairs(new String[] {"man", "moon", "good", "night"}));
    }

    public static Map<String, String> pairs(String[] strings) {
        final Map<String, String> result = new HashMap<>();
        for (String string : strings) {
            result.put(string.substring(0, 1), string.substring(string.length() - 1, string.length()));
        }
        return result;
    }
}