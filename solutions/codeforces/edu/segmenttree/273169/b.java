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
    long[] a = new long[n];
    for (int i = 0; i < n; ++i) {
      a[i] = in.nextInt();
    }

    SegmentTree st = new SegmentTree(a, 0, n - 1);
    for (int i = 0; i < m; ++i) {
      int x = in.nextInt(), b = in.nextInt(), c = in.nextInt();
      if (x == 1) {
        st.update(b, c);
      } else {
        out.println(st.query(b, c - 1));
      }
    }
  }

  // Segment Tree that computes the minimum value in a range.
  class SegmentTree {
    int l, r;
    SegmentTree lc, rc;
    long mn;

    SegmentTree(long[] a, int l, int r) {
      this.l = l;
      this.r = r;

      if (l == r) {
        mn = a[l];
        return;
      }

      int mid = l + (r - l) / 2;
      lc = new SegmentTree(a, l, mid);
      rc = new SegmentTree(a, mid + 1, r);
      compute();
    }

    long query(int l, int r) {
      if (this.l > r || this.r < l) {
        return Integer.MAX_VALUE;
      }
      if (this.l >= l && this.r <= r) {
        return mn;
      }

      return Math.min(lc.query(l, r), rc.query(l, r));
    }

    void update(int i, long v) {
      if (l == r) {
        mn = v;
        return;
      }

      int mid = l + (r - l) / 2;
      if (i <= mid) {
        lc.update(i, v);
      } else {
        rc.update(i, v);
      }
      compute();
    }

    void compute() {
      mn = Math.min(lc.mn, rc.mn);
    }
  }
}