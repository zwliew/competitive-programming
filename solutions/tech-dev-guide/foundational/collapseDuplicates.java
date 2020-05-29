/**
 * https://techdevguide.withgoogle.com/paths/foundational/collapseduplicates-problem-fix/#!
 *
 * Fix this duplicate collapsing code:
 * public String collapseDuplicates(String a) {
 *     int i = 0;
 *     String result = "";
 *     while (i < a.length()) {
 *         char ch = a.charAt(i);
 *         result += ch;
 *         while (a.charAt(i+1) == ch) {
 *             i++;
 *         }
 *         i++;
 *     }
 *     return result;
 * }
 *
 * collapseDuplicates("a") → "a"
 * collapseDuplicates("aa") → "a"
 * collapseDuplicates("abc") → "abc"
 */

class Main {
    public static void main(String[] args) {
        System.out.println(collapseDuplicates("a");
        System.out.println(collapseDuplicates("aa");
        System.out.println(collapseDuplicates("abc");
    }

    public static String collapseDuplicates(String a) {
        int i = 0;
        String result = "";
        while (i < a.length()) {
            char ch = a.charAt(i);
            result += ch;
            while (i < a.length() && a.charAt(i) == ch) {
                i++;
            }
        }
        return result;
    }
}