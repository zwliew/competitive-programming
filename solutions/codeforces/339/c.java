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
    var s = in.nextLine();
    int m = in.nextInt();
    var avail = new ArrayList<Integer>();
    for (int i = 1; i <= 10; ++i) {
      if (s.charAt(i - 1) == '1') {
        avail.add(i);
      }
    }

    var ans = new ArrayList<Integer>();
    if (dfs(avail, ans, m, 0, 0)) {
      out.println("YES");
      for (int x : ans) {
        out.print(x + " ");
      }
    } else {
      out.print("NO");
    }
  }

  boolean dfs(ArrayList<Integer> avail, ArrayList<Integer> ans, int left, int bal, int prev) {
    if (left == 0) {
      return true;
    }
    for (int candidate : avail) {
      if (prev == candidate)
        continue;
      if (bal <= 0 && bal + candidate > 0) {
        ans.add(candidate);
        if (dfs(avail, ans, left - 1, bal + candidate, candidate)) {
          return true;
        }
        ans.remove(ans.size() - 1);
      } else if (bal > 0 && bal - candidate < 0) {
        ans.add(candidate);
        if (dfs(avail, ans, left - 1, bal - candidate, candidate)) {
          return true;
        }
        ans.remove(ans.size() - 1);
      }
    }
    return false;
  }
}