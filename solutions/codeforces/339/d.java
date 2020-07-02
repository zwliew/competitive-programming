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

  public static void main(final String[] args) {
    int n = nextInt(), m = nextInt();
    int[] a = new int[1 << n];
    for (int i = 0; i < (1 << n); ++i) {
      a[i] = nextInt();
    }

    SegmentTree st = new SegmentTree(a, 0, (1 << n) - 1);

    while (m-- > 0) {
      int p = nextInt(), b = nextInt();
      --p;
      st.assign(p, b);
      System.out.println(st.val);
    }
  }
}

class SegmentTree {
  int lo, hi;
  SegmentTree left, right;
  int val;
  boolean xor;

  SegmentTree(int[] a, int lo, int hi) {
    this.lo = lo;
    this.hi = hi;

    if (lo == hi) {
      val = a[lo];
      return;
    }

    int mid = lo + (hi - lo) / 2;
    left = new SegmentTree(a, lo, mid);
    right = new SegmentTree(a, mid + 1, hi);

    int len = hi - lo + 1;
    int power = 0;
    while (len > 1) {
      len >>= 1;
      ++power;
    }
    xor = power % 2 == 0;

    compute();
  }

  void assign(int idx, int val) {
    if (lo == hi) {
      this.val = val;
      return;
    }

    if (idx <= left.hi) {
      left.assign(idx, val);
    } else {
      right.assign(idx, val);
    }
    compute();
  }

  void compute() {
    val = xor ? left.val ^ right.val : left.val | right.val;
  }
}