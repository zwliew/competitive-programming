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
    String s = in.next();
    // Original brute force solution. Time complexity: O(len(s)^3)
    // for (int i = 0; i < s.length(); ++i) {
    // int ci = s.charAt(i) - '0';
    // if (ci % 8 == 0) {
    // out.println("YES");
    // out.print(ci);
    // return;
    // }

    // for (int j = i + 1; j < s.length(); ++j) {
    // int cj = s.charAt(j) - '0';
    // if ((ci * 10 + cj) % 8 == 0) {
    // out.println("YES");
    // out.print(ci * 10 + cj);
    // return;
    // }

    // for (int k = j + 1; k < s.length(); ++k) {
    // int ck = s.charAt(k) - '0';
    // if ((ci * 100 + cj * 10 + ck) % 8 == 0) {
    // out.println("YES");
    // out.print(ci * 100 + cj * 10 + ck);
    // return;
    // }
    // }
    // }
    // }
    // out.print("NO");

    // Faster DP solution. Time complexity: O(len(s))
    boolean[][] dp = new boolean[s.length()][8];
    int[][] parent = new int[s.length()][8];
    for (int i = 0; i < s.length(); ++i) {
      int cur = (s.charAt(i) - '0') % 8;
      dp[i][cur] = true;
      parent[i][cur] = -1;
      if (i > 0) {
        for (int j = 0; j < 8; ++j) {
          if (dp[i - 1][j]) {
            dp[i][j] = true;
            parent[i][j] = j;
            dp[i][(j * 10 + cur) % 8] = true;
            parent[i][(j * 10 + cur) % 8] = j;
          }
        }
      }
    }

    for (int i = 0; i < s.length(); ++i) {
      if (dp[i][0]) {
        int curi = i, curj = 0;
        var sb = new StringBuilder();
        while (curj != -1) {
          if (parent[curi][curj] == -1 || parent[curi][curj] != curj) {
            sb.append(s.charAt(curi));
          }
          curj = parent[curi][curj];
          --curi;
        }

        out.println("YES");
        out.println(sb.reverse().toString());
        return;
      }
    }

    out.print("NO");
  }
}