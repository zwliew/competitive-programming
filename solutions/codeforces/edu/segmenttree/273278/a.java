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
    out.println(st.mx);
    for (int i = 0; i < m; ++i) {
      int idx = in.nextInt(), v = in.nextInt();
      st.update(idx, v);
      out.println(st.mx);
    }
  }

  // Segment Tree that computes the max subarray in a range.
  class SegmentTree {
    int l, r;
    SegmentTree lChild, rChild;
    long pre, suf, mx, sum;

    SegmentTree(long[] a, int l, int r) {
      this.l = l;
      this.r = r;

      if (l == r) {
        sum = a[l];
        mx = pre = suf = Math.max(0, a[l]);
        return;
      }

      int mid = l + (r - l) / 2;
      lChild = new SegmentTree(a, l, mid);
      rChild = new SegmentTree(a, mid + 1, r);
      compute();
    }

    void update(int i, long v) {
      if (l == r) {
        sum = v;
        mx = pre = suf = Math.max(0, v);
        return;
      }

      int mid = l + (r - l) / 2;
      if (i <= mid) {
        lChild.update(i, v);
      } else {
        rChild.update(i, v);
      }
      compute();
    }

    void compute() {
      pre = Math.max(lChild.pre, lChild.sum + rChild.pre);
      suf = Math.max(rChild.suf, rChild.sum + lChild.suf);
      sum = lChild.sum + rChild.sum;
      mx = Math.max(Math.max(lChild.mx, rChild.mx), rChild.pre + lChild.suf);
    }
  }
}