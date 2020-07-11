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
    final String s = in.next();
    long pre = 0, suf = 0;
    int pivot = 0;
    for (int i = 0; i < s.length(); ++i) {
      char c = s.charAt(i);
      if (c == '^') {
        pivot = i;
        break;
      }
    }
    for (int i = 0; i < s.length(); ++i) {
      char c = s.charAt(i);
      if (Character.isDigit(c)) {
        long d = c - '0';
        if (i < pivot) {
          pre += (pivot - i) * d;
        } else {
          suf += (i - pivot) * d;
        }
      }
    }
    if (pre == suf) {
      out.print("balance");
    } else if (pre > suf) {
      out.print("left");
    } else {
      out.print("right");
    }
  }
}