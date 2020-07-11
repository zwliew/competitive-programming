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

    // Editorial solution: O(N)
    int[] cnt = new int[n * 2 + 1];
    for (int i = 0; i < n; ++i) {
      int a = in.nextInt();
      cnt[a]++;
    }
    int ans = 0;
    for (int i = 1; i < n * 2; ++i) {
      int amt = Math.max(0, cnt[i] - 1);
      ans += amt;
      cnt[i + 1] += amt;
    }
    out.print(ans);

    // Original solution: (ONlogN)
    // int[] a = new int[n];
    // for (int i = 0; i < n; ++i) {
    //   a[i] = in.nextInt();
    // }
    // Arrays.sort(a);
    // int next = 1;
    // int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //   if (a[i] > next) {
    //     next = a[i] + 1;
    //   } else {
    //     ans += next - a[i];
    //     ++next;
    //   }
    // }
    // out.print(ans);
  }
}