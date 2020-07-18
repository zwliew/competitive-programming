import java.io.*;
import java.util.*;

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
    int n = in.nextInt(), k = in.nextInt();
    int[] aPreSum = new int[n + 1];
    int[] bPreSum = new int[n + 1];
    String s = in.next();
    for (int i = 1; i <= n; ++i) {
      bPreSum[i] = bPreSum[i - 1] + (s.charAt(i - 1) == 'b' ? 1 : 0);
      aPreSum[i] = aPreSum[i - 1] + (s.charAt(i - 1) == 'a' ? 1 : 0);
    }

    out.print(Math.max(count(n, bPreSum, k), count(n, aPreSum, k)));
  }

  int count(int n, int[] preSum, int k) {
    int j = 0;
    int best = 0;
    for (int i = 1; i <= n; ++i) {
      while (j < n && preSum[j + 1] - preSum[i - 1] <= k) {
        ++j;
      }
      best = Math.max(best, j - i + 1);
    }
    return best;
  }
}