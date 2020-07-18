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
    int n = in.nextInt();
    var adj = new ArrayList<ArrayList<Integer>>();
    var intervals = new ArrayList<Interval>();
    while (n-- > 0) {
      int x = in.nextInt(), y = in.nextInt(), z = in.nextInt();
      if (x == 1) {
        intervals.add(new Interval(y, z));
        adj.add(new ArrayList<Integer>());
        for (int i = 0; i < adj.size() - 1; ++i) {
          var interval = intervals.get(i);
          if ((interval.l < y && interval.r > y) || (interval.l < z && interval.r > z)) {
            adj.get(adj.size() - 1).add(i);
          }
          if ((y < interval.l && z > interval.l) || (y < interval.r && z > interval.r)) {
            adj.get(i).add(adj.size() - 1);
          }
        }
      } else {
        boolean[] vis = new boolean[adj.size()];
        out.println(dfs(adj, vis, z - 1, y - 1) ? "YES" : "NO");
      }
    }
  }

  static boolean dfs(ArrayList<ArrayList<Integer>> adj, boolean[] vis, int target, int u) {
    if (u == target) {
      return true;
    }
    vis[u] = true;
    for (int v : adj.get(u)) {
      if (!vis[v] && dfs(adj, vis, target, v)) {
        return true;
      }
    }
    return false;
  }
}

class Interval {
  int l, r;

  Interval(int l, int r) {
    this.l = l;
    this.r = r;
  }
}