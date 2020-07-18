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

    int ans = n * 4;
    var pts = new ArrayList<Point>();
    for (int i = 0; i < n; ++i) {
      int x = in.nextInt(), y = in.nextInt();
      if (x != 0 && y != 0) {
        ans += 2;
      }
      pts.add(new Point(x, y));
    }

    Collections.sort(pts);

    out.println(ans);
    for (var pt : pts) {
      int x = pt.x;
      int y = pt.y;

      if (x != 0) {
        out.print("1 " + Math.abs(x) + ' ');
        if (x > 0) {
          out.print('R');
        } else {
          out.print('L');
        }
        out.println();
      }

      if (y != 0) {
        out.print("1 " + Math.abs(y) + " ");
        if (y > 0) {
          out.print('U');
        } else {
          out.print('D');
        }
        out.println();
      }

      out.println(2);

      if (y != 0) {
        out.print("1 " + Math.abs(y) + ' ');
        if (y > 0) {
          out.print('D');
        } else {
          out.print('U');
        }
        out.println();
      }

      if (x != 0) {
        out.print("1 " + Math.abs(x) + ' ');
        if (x > 0) {
          out.print('L');
        } else {
          out.print('R');
        }
        out.println();
      }

      out.println(3);
    }
  }

  class Point implements Comparable<Point> {
    int x, y;

    Point(int x, int y) {
      this.x = x;
      this.y = y;
    }

    public int compareTo(Point o) {
      if (Math.abs(x) != Math.abs(o.x)) {
        return Math.abs(x) < Math.abs(o.x) ? -1 : 1;
      }
      if (Math.abs(y) != Math.abs(o.y)) {
        return Math.abs(y) < Math.abs(o.y) ? -1 : 1;
      }
      return 0;
    }
  }
}