import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class template {
  private static final PrintWriter out = new PrintWriter(System.out);
  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static StringTokenizer st;

  private static String next() {
    while (st == null || !st.hasMoreElements()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (final IOException e) {
        e.printStackTrace();
      }
    }
    return st.nextToken();
  }

  private static int nextInt() {
    return Integer.parseInt(next());
  }

  private static long nextLong() {
    return Long.parseLong(next());
  }

  private static double nextDouble() {
    return Double.parseDouble(next());
  }

  private static String nextLine() {
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

  static class Coord {
    int x;
    int y;

    Coord(final int x, final int y) {
      this.x = x;
      this.y = y;
    }
  }

  static int find(final int[] p, final int u) {
    return u == p[u] ? u : (p[u] = find(p, p[u]));
  }

  static int sz;

  static void join(final int[] p, int u, int v) {
    u = find(p, u);
    v = find(p, v);
    if (u == v)
      return;
    p[u] = v;
    --sz;
  }

  public static void main(final String[] args) {
    final int n = nextInt();

    final Coord[] arr = new Coord[n];
    for (int i = 0; i < n; ++i) {
      final int x = nextInt(), y = nextInt();
      arr[i] = new Coord(x, y);
    }

    final int[] p = new int[n];
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }

    sz = n;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        if (arr[i].x == arr[j].x || arr[i].y == arr[j].y) {
          join(p, i, j);
        }
      }
    }

    System.out.print(sz - 1);
  }
}