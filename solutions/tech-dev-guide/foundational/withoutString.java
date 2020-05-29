/**
 * https://techdevguide.withgoogle.com/paths/foundational/withoutstring-problem-strings-base-remove-return/#!
 *
 * Given two strings, base and remove, return a version of the base string where
 * all instances of the remove string have been removed (not case sensitive).
 * You may assume that the remove string is length 1 or more.
 * Remove only non-overlapping instances, so with "xxx" removing "xx" leaves "x".
 *
 * withoutString("Hello there", "llo") → "He there"
 * withoutString("Hello there", "e") → "Hllo thr"
 * withoutString("Hello there", "x") → "Hello there"
 */

public static String withoutString(String base, String remove) {
    final String baseLower = base.toLowerCase();
    final String removeLower = remove.toLowerCase();
    final int removeLen = remove.length();
    String result = "";
    int index = 0;
    while ((index + removeLen) <= base.length()) {
        if ((baseLower.substring(index, index + removeLen)).equals(removeLower)) {
            index += removeLen;
        } else {
            result += base.charAt(index);
            index++;
        }
    }
    result += base.substring(index, base.length());
    return result;
}