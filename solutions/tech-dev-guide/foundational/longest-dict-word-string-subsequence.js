/**
 * https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string/#!
 *
 * Given a string S and a set of words D, find the longest word in D that is a
 * subsequence of S.
 *
 * Word W is a subsequence of S if some number of characters, possibly zero,
 * can be deleted from S to form W, without reordering the remaining characters.
 *
 * Note: D can appear in any format (list, hash table, prefix tree, etc.)
 *
 * For example, given the input of S = "abppplee" and D = {"able", "ale", "apple",
 * "bale", "kangaroo"} the correct output would be "apple"
 *
 * - The words "able" and "ale" are both subsequences of S, but they are shorter
 *   than "apple".
 * - The word "bale" is not a subsequence of S because even though S has all the
 *   right letters, they are not in the right order.
 * - The word "kangaroo" is the longest word in D, but it isn't a subsequence of S.
 *
 * *Learning objectives*
 * This question gives you the chance to practise with algorithms and data
 * structures. It's also a good example of why careful analysis for Big-O
 * performance is often worthwhile, as is careful exploration of common and
 * worst-case input conditions.
 */

function findLongestWordInString(string, words) {
  let iterations = 0;
  let found = false;
  let index = 0;
  D.sort((a, b) => b > a);
  while (!found && index < D.length) {
    let indexS = 0;
    let indexWord = 0;
    while (indexS < S.length && indexWord < D[index].length) {
      if (D[index][indexWord] === S[indexS]) {
        indexWord++;
      }
      indexS++;
      iterations++;
    }
    if (indexWord === D[index].length) {
      found = true;
    }
    index++;
  }
  console.log(`Iterations: ${iterations}.`);
  return found ? index - 1 : -1;
}

const S = "abppplee";
const D = ["able", "ale", "apple", "bale", "kangaroo"];
const index = findLongestWordInString(S, D);
if (index >= 0) {
  console.log(`The longest word that is a subsequence is ${D[index]} with ${D[index].length} letters.`);
} else {
  console.log('No word that is a subsequence is found.');
}
