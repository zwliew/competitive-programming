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
    int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
    char[][] grid = new char[n][m];
    int cnt = 0;
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
      String s = in.nextLine();
      for (int j = 0; j < m; ++j) {
        char c = s.charAt(j);
        grid[i][j] = c;
        if (c == '.') {
          ++cnt;
          x = i;
          y = j;
        }
      }
    }

    cnt -= k;
    dfs(grid, n, m, x, y, cnt);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'E') {
          out.print('.');
        } else if (grid[i][j] == '.') {
          out.print('X');
        } else {
          out.print(grid[i][j]);
        }
      }
      out.println();
    }
  }

  int dfs(char[][] grid, int h, int w, int r, int c, int left) {
    grid[r][c] = 'E';
    int cnt = 1;
    --left;
    if (left == 0)
      return 1;
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if ((dr == 0) == (dc == 0))
          continue;
        int nr = r + dr;
        int nc = c + dc;
        if (nr < 0 || nc < 0 || nr >= h || nc >= w)
          continue;
        if (grid[nr][nc] != '.')
          continue;
        int cur = dfs(grid, h, w, nr, nc, left);
        cnt += cur;
        left -= cur;
        if (left == 0)
          break;
      }
      if (left == 0)
        break;
    }
    return cnt;
  }
}
