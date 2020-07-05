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
    int[] arr = new int[n];
    for (int i = 0; i < n; ++i) {
      arr[i] = in.nextInt();
    }

    int foundIdx = n;
    for (int i = 1; i < n; ++i) {
      if (arr[i - 1] > arr[i]) {
        if (foundIdx < n) {
          out.print(-1);
          return;
        }
        foundIdx = i;
      }
    }
    
    int curMin = Integer.MAX_VALUE;
    for (int i = 0; i < foundIdx; ++i) {
      curMin = Math.min(curMin, arr[i]);
    }
    for (int i = foundIdx; i < n; ++i) {
      if (arr[i] > curMin) {
        out.print(-1);
        return;
      }
    }

    out.print(n - foundIdx);
  }
}