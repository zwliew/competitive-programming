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
    int h = in.nextInt(), w = in.nextInt();
    int[][] d = new int[2][2];
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        d[i][j] = in.nextInt();
      }
    }

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int f = d[0][i] + d[1][j];
        int s = Math.max(d[0][i ^ 1], d[1][j ^ 1]);
        if ((h >= f && w >= s) || (h >= s && w >= f)) {
          out.print("YES");
          return;
        }
      }
    }
    out.print("NO");
  }
}
