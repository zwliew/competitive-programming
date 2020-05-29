/**
 * https://techdevguide.withgoogle.com/paths/foundational/using-strings-in-java-manipulation-review/#!
 */
class Main {
    public static void main(String[] args) {
        String message = "Hello world!";

        message = message.concat(" Lovely day, isn't it?");

        message = message.toUpperCase(); // or toLowerCase()

        message = message.replace('O', '0');
        message = message.replace('E', '3');
        message = message.replace('L', '1');

        char[] characters = message.toCharArray(); // {'H','3', '1', '1', ...}

        for (char c : characters) {
            System.out.print(c);
        }
        System.out.println();

        System.out.println(message);
    }
}