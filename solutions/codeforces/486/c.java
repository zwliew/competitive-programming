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
    final int n = nextInt();
    final int p = nextInt() - 1;
    final String s = nextLine();
    int ans = 0;
    int cmin = (int) 1e9, cmax = (int) -1e9;
    for (int i = 0; i < n / 2; ++i) {
      if (s.charAt(i) != s.charAt(n - 1 - i)) {
        int diff = Math.abs(s.charAt(i) - s.charAt(n - 1 - i));
        ans += Math.min(diff, 26 - diff);
        if (p < n / 2) {
          cmin = Math.min(cmin, i);
          cmax = Math.max(cmax, i);
        } else {
          cmin = Math.min(cmin, n - 1 - i);
          cmax = Math.max(cmax, n - 1 - i);
        }
      }
    }

    if (ans == 0) {
      out.print(0);
      out.close();
      return;
    }

    int dist = 0;
    if (cmax <= p) {
      dist = p - cmin;
    } else {
      dist = Math.min(2 * (cmax - p) + p - cmin, 2 * (p - cmin) + cmax - p);
    }

    out.println(ans + dist);
    out.close();
  }
}
