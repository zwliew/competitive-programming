/**
 * https://techdevguide.withgoogle.com/paths/foundational/subnumbers-problem-string-return-sum/#!
 *
 * Given a string, return the sum of the numbers appearing in the string,
 * ignoring all other characters. A number is a series of 1 or more digit chars
 * in a row. (Note: Character.isDigit(char) tests if a char is one of the chars
 * '0', '1', .. '9'. Integer.parseInt(string) converts a string to an int.)
 *
 * sumNumbers("abc123xyz") → 123
 * sumNumbers("aa11b33") → 44
 * sumNumbers("7 11") → 18
 */
public static int sumNumbers(String str) {
  int result = 0;
  int startIndex = 0;
  while (startIndex < str.length()) {
      int endIndex = startIndex + 1;
      while (endIndex <= str.length() && str.substring(startIndex, endIndex).matches("\\d+")) {
          endIndex++;
      }
      if (endIndex > startIndex + 1) {
          result += Integer.parseInt(str.substring(startIndex, endIndex - 1));
      }
      startIndex = endIndex;
  }
  return result;
}