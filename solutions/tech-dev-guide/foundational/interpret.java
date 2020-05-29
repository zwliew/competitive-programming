/**
 * https://techdevguide.withgoogle.com/paths/foundational/interpreter-problem-for-java/#!
 *
 * Write a simple interpreter which understands "+", "-", and "*" operations.
 * Apply the operations in order using command/arg pairs starting with the
 * initial value of `value`. If you encounter an unknown command, return -1.
 *
 * interpret(1, ["+"], [1]) → 2
 * interpret(4, ["-"], [2]) → 2
 * interpret(1, ["+", "*"], [1, 3]) → 6
 */
class Main {
    public static void main(String[] args) {
        System.out.println(interpret(1, new String[] {"+"}, new int[] {1}));
        System.out.println(interpret(4, new String[] {"-"}, new int[] {2}));
        System.out.println(interpret(1, new String[] {"+", "*"}, new int[] {1, 3}));
    }

    public static int interpret(int value, String[] commands, int[] args) {
        int result = value;
        for (int i = 0; i < commands.length; i++) {
            final String cmd = commands[i];
            final int arg = args[i];

            if (cmd.equals("+")) {
                result += arg;
            } else if (cmd.equals("-")) {
                result -= arg;
            } else if (cmd.equals("*")) {
                result *= arg;
            } else {
                return -1;
            }
        }
        return result;
    }
}