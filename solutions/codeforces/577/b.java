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
    int n = in.nextInt();
    int m = in.nextInt();
    if (n > m) {
      out.print("YES");
      return;
    }
    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = in.nextInt();
      a[i] %= m;
    }

    boolean[][] dp = new boolean[2][m];
    for (int i = 0; i < n; ++i) {
      int cur = i & 1;
      int prev = cur ^ 1;
      for (int j = 0; j < m; ++j) {
        dp[cur][j] = a[i] == j || dp[prev][j] || dp[prev][(j - a[i] + m) % m];
        if (j == 0 && dp[cur][j]) {
          out.print("YES");
          return;
        }
      }
    }

    out.print("NO");
  }
}
