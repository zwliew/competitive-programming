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
    long n = in.nextLong();
    long best = Long.MAX_VALUE;
    for (long i = 1; i <= 90; ++i) {
      double a = (-i + Math.sqrt(i * i + 4 * n)) / 2;
      long ai = (long) a;
      if (a == ai && ai > 0) {
        int sum = 0;
        long tmp = ai;
        while (tmp > 0) {
          sum += tmp % 10;
          tmp /= 10;
        }
        if (ai * ai == n - sum * ai) {
          best = Math.min(best, ai);
        }
      }
    }
    out.print(best == Long.MAX_VALUE ? -1 : best);
  }
}