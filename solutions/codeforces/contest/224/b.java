import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

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
    final var reader = new InputReader(System.in);
    final var writer = new PrintWriter(System.out);
    solve(reader, writer);
    writer.close();
  }

  static void solve(InputReader in, PrintWriter out) {
    int n = in.nextInt(), k = in.nextInt();
    int[] a = new int[n];
    var hm = new HashMap<Integer, Integer>();
    for (int i = 0; i < n; ++i) {
      a[i] = in.nextInt();
      if (!hm.containsKey(a[i])) {
        hm.put(a[i], 1);
      } else {
        hm.put(a[i], hm.get(a[i]) + 1);
      }
    }

    if (hm.size() < k) {
      out.print("-1 -1");
      return;
    }

    int i = 0;
    while (hm.size() >= k) {
      int cur = hm.get(a[i]);
      if (cur == 1) {
        hm.remove(a[i]);
      } else {
        hm.put(a[i], cur - 1);
      }
      ++i;
    }

    int j = n - 1;
    while (j > i && a[j] == a[j - 1]) {
      --j;
    }

    out.print(i + " " + (j + 1));
  }
}