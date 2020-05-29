/**
 * https://techdevguide.withgoogle.com/paths/foundational/using-arrays-in-java-intro-no-worries
 */
class Main {
    public static void main(String[] args) {
        // Initialization
        int[] ages = {17, 21, 18, 19};
        boolean[] student = new boolean[4];

        student[0] = true;
        student[1] = false;
        student[2] = false;
        student[3] = true;
        
        for (int i = 0; i < ages.length; i++) {
            System.out.println(ages[i]);
        }
     }
}