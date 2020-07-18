import java.io.*;
import java.util.*;

public class template {
  static class InputReader {
    private final BufferedReader br;
    private StringTokenizer st;

    InputReader(final InputStream in) {
      br = new BufferedReader(new InputStreamReader(in));
    }

    String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (final IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    String nextLine() {
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
  }

  public static void main(final String[] args) {
    final var in = new InputReader(System.in);
    final var out = new PrintWriter(System.out);
    new template().solve(in, out);
    out.close();
  }

  void solve(InputReader in, PrintWriter out) {
    var s = in.next();
    var rev = new StringBuilder(s).reverse().toString();
    if (check(s) || check(rev)) {
      out.print("YES");
    } else {
      out.print("NO");
    }
  }

  boolean check(String s) {
    boolean first = false, second = false;
    for (int i = 0; i < s.length() - 1; ++i) {
      char a = s.charAt(i);
      char b = s.charAt(i + 1);
      if (!first && a == 'A' && b == 'B') {
        first = true;
        ++i;
      } else if (!second && a == 'B' && b == 'A') {
        second = true;
        ++i;
      }
    }
    return first && second;
  }
}