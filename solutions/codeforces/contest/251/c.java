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
    int n = nextInt();
    int d = nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; ++i) {
      arr[i] = nextInt();
    }

    long cnt = 0;
    int j = 0;
    for (int i = 0; i < n - 2; ++i) {
      while (j < n - 1 && arr[j + 1] - arr[i] <= d) {
        ++j;
      }
      cnt += (long) (j - i) * (j - i - 1) / 2;
    }
    out.print(cnt);

    out.close();
  }
}
