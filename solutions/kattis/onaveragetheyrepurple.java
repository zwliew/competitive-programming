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
    int n = in.nextInt(), m = in.nextInt();
    var adj = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; ++i) {
      adj.add(new ArrayList<Integer>());
    }
    for (int i = 0; i < m; ++i) {
      int u = in.nextInt(), v = in.nextInt();
      --u;
      --v;
      adj.get(u).add(v);
      adj.get(v).add(u);
    }

    var dist = new int[n];
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[0] = 0;
    var q = new ArrayDeque<Integer>();
    q.add(0);
    while (!q.isEmpty()) {
      int u = q.remove();
      if (u == n - 1) {
        out.print(dist[u] - 1);
        return;
      }

      for (int v : adj.get(u)) {
        if (dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          q.add(v);
        }
      }
    }
  }
}