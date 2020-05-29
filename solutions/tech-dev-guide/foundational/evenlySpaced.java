/**
 * https://techdevguide.withgoogle.com/paths/foundational/evenlyspaced-problem-medium/#!
 *
 * Given three ints, a b c, one of them is small, one is medium and one is large.
 * Return true if the three values are evenly spaced, so the difference between
 * small and medium is the same as the difference between medium and large.
 *
 * evenlySpaced(2, 4, 6) → true
 * evenlySpaced(4, 6, 2) → true
 * evenlySpaced(4, 6, 3) → false
 */

class Main {
    public static void main(String[] args) {
        System.out.println(evenlySpaced(2, 4, 6));
        System.out.println(evenlySpaced(4, 6, 2));
        System.out.println(evenlySpaced(4, 6, 3));
    }

    public static boolean evenlySpaced(int a, int b, int c) {
        if (a < b && b < c) {
            return b - a == c - b;
        }
        
        if (b < c && c < a) {
            return a - c == c - b;
        }

        return b - a == a - c;
    }
}