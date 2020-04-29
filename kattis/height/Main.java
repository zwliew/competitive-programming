package kattis.height;

public import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static final PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
  private static StringTokenizer st;

  private static String next() {
    while (st == null || !st.hasMoreElements()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    return st.nextToken();
  }

  private static int nextInt() {
    return Integer.parseInt(next());
  }

  private static long nextLong() {
    return Long.parseLong(next());
  }

  private static double nextDouble() {
    return Double.parseDouble(next());
  }

  private static String nextLine() {
    String res = null;
    while (res == null || res.isEmpty()) {
      try {
        return br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    return res;
  }

  public static void main(String[] args) {
    // Count the number of people shorter than the person to be added
    int p = nextInt();
    while (p-- > 0) {
      int k = nextInt();
      var list = new ArrayList<Integer>();
      int ans = 0;
      for (int i = 0; i < 20; ++i) {
        int cur = nextInt();
        for (int x : list) {
          if (x > cur) {
            ++ans;
          }
        }
        list.add(cur);
      }
      System.out.println(k + " " + ans);
    }
  }
}
class test {

}
