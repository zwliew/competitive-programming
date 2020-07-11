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
    int bestIdx = -1;
    int[] s = new int[n];
    int[] r = new int[n];
    int[] h = new int[n];
    int[] c = new int[n];
    for (int i = 0; i < n; ++i) {
      s[i] = in.nextInt();
      r[i] = in.nextInt();
      h[i] = in.nextInt();
      c[i] = in.nextInt();
    }

    for (int i = 0; i < n; ++i) {
      boolean ok = true;
      for (int j = 0; j < n && ok; ++j) {
        if (s[i] < s[j] && r[i] < r[j] && h[i] < h[j]) {
          ok = false;
        }
      }
      if (ok) {
        if (bestIdx == -1 || c[bestIdx] > c[i]) {
          bestIdx = i;
        }
      }
    }

    out.print(bestIdx + 1);
  }
}