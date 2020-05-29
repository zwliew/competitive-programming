/**
 * https://techdevguide.withgoogle.com/paths/foundational/software-debugging-warmup/#!
 *
 * Given 2 int values greater than 0, return whichever value is nearest to
 * 21 without going over. Return 0 if they both go over.
 *
 * blackjack(19, 21) → 21
 * blackjack(21, 19) → 21
 * blackjack(19, 22) → 19
 */

class Main {
    public static void main(String[] args) {
        System.out.println(blackjack(19, 21));
        System.out.println(blackjack(21, 19));
        System.out.println(blackjack(19, 22));
    }

    public static int blackjack(int a, int b) {
        final boolean aOver = a > 21;
        final boolean bOver = b > 21;
        if (aOver && bOver) {
            return 0;
        }
        if (aOver) {
            return b;
        }
        if (bOver) {
            return a;
        }
        return a > b ? a : b;
    }
}