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
    int c = in.nextInt(), n = in.nextInt(), m = in.nextInt();
    long[][] cnt = new long[2][c + 1];
    for (int i = 0; i < n; ++i) {
      int x = in.nextInt();
      ++cnt[0][x];
    }

    long[] ans = new long[51];
    ans[0] = n;
    for (int i = 1, cur = 1, prev = 0; i <= 50; ++i, cur ^= 1, prev ^= 1) {
      Arrays.fill(cnt[cur], 0);
      for (int j = 1; j <= c; ++j) {
        int upd = j * 2;
        if (upd > c) {
          cnt[cur][upd / 2] += 2 * cnt[prev][j];
        } else {
          cnt[cur][upd] += cnt[prev][j];
        }
      }

      for (int j = 1; j <= c; ++j) {
        ans[i] += cnt[cur][j];
      }
    }

    for (int i = 0; i < m; ++i) {
      int d = in.nextInt();
      out.println(ans[d]);
    }
  }
}
