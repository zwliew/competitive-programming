/**
 * https://techdevguide.withgoogle.com/paths/foundational/collapseduplicates-problem-fix/#!
 *
 * We want to make a row of bricks that is goal inches long.
 * We have a number of small bricks (1 inch each) and big bricks (5 inches each).
 * Return true if it is possible to make the goal by choosing from the given bricks.
 * This is a little harder than it looks and can be done without any loops.
 * See also: Introduction to MakeBricks (http://codingbat.com/doc/practice/makebricks-introduction.html)
 *
 * makeBricks(3, 1, 8) → true
 * makeBricks(3, 1, 9) → false
 * makeBricks(3, 2, 10) → true
 */

class Main {
    public static void main(String[] args) {
        System.out.println(makeBricks(3, 1, 8);
        System.out.println(makeBricks(3, 1, 9);
        System.out.println(makeBricks(3, 2, 10);
    }

    public static boolean makeBricks(int small, int big, int goal) {
        final int numBig = big > goal / 5 ? goal / 5 : big;
        final int remainder = goal - numBig * 5;
        return remainder <= small;
    }
}