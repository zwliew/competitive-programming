import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Test {
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
    int n = nextInt();
    String prev = nextLine();
    boolean asc = true;
    boolean desc = true;
    for (int i = 1; i < n; ++i) {
      String x = nextLine();
      int cmp = x.compareTo(prev);
      if (cmp < 0) {
        asc = false;
      } else if (cmp > 0) {
        desc = false;
      }
      prev = x;
    }
    if (asc) {
      System.out.print("INCREASING");
    } else if (desc) {
      System.out.print("DECREASING");
    } else {
      System.out.print("NEITHER");
    }
  }
}
package kattis.lineup;

public class Main {

}
