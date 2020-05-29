/**
 * https://techdevguide.withgoogle.com/paths/foundational/encoder-problem-hard/#!
 *
 * Write a function that replaces the words in `raw` with the words in
 * `code_words` such that the first occurrence of each word in `raw` is
 * assigned the first unassigned word in `code_words`.
 *
 * encoder(["a"], ["1", "2", "3", "4"]) → ["1"]
 * encoder(["a", "b"], ["1", "2", "3", "4"]) → ["1", "2"]
 * encoder(["a", "b", "a"], ["1", "2", "3", "4"]) → ["1", "2", "1"]
 */
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Main {
    public static void main(String[] args) {
        System.out.println(encoder(new String[] {"a"}, new String[] {"1", "2", "3", "4"}));
        System.out.println(encoder(new String[] {"a", "b"}, new String[] {"1", "2", "3", "4"}));
        System.out.println(encoder(new String[] {"a", "b", "a"}, new String[] {"1", "2", "3", "4"}));
    }

    public static String[] encoder(String[] raw, String[] code_words) {
        final Map<String, String> map = new HashMap<>();
        final List<String> list = new ArrayList<>();
        int codeWordIndex = 0;
        for (String s : raw) {
            final String value = map.get(s);
            if (value == null) {
              map.put(s, code_words[codeWordIndex]);
              list.add(code_words[codeWordIndex]);
              codeWordIndex++;
            } else {
              list.add(value);
            }
        }
        return list.toArray(new String[0]);
    }
}