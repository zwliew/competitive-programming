import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class template {
  private static final PrintWriter out = new PrintWriter(System.out);
  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static StringTokenizer st;

  private static String next() {
    while (st == null || !st.hasMoreElements()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (final IOException e) {
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
    final String res = null;
    while (res == null || res.isEmpty()) {
      try {
        return br.readLine();
      } catch (final IOException e) {
        e.printStackTrace();
      }
    }
    return res;
  }

  public static void main(final String[] args) {
    int n = nextInt();
    int fours = (int) 1e9;
    int sevens = (int) 1e9;
    for (int x = 0; x <= n / 4; ++x) {
      int y = n - 4 * x;
      if (y % 7 > 0)
        continue;
      y /= 7;
      if (x + y < fours + sevens || (fours + sevens == x + y && x > fours)) {
        fours = x;
        sevens = y;
      }
    }

    if (fours + sevens > 1e9) {
      out.print(-1);
      out.close();
      return;
    }

    while (fours-- > 0) {
      out.print(4);
    }
    while (sevens-- > 0) {
      out.print(7);
    }
    out.close();
  }
}
