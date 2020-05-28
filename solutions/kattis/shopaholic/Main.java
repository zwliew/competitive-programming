import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class test {
  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static StringTokenizer st;

  private static String next() {
    while (st == null || !st.hasMoreElements()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
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
    String res = null;
    while (res == null || res.isEmpty()) {
      try {
        return br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    return res;
  }

  public static void main(String[] args) {
    int n = nextInt();
    var items = new ArrayList<Integer>();
    for (int i = 0; i < n; ++i) {
      int x = nextInt();
      items.add(x);
    }
    Collections.sort(items, Collections.reverseOrder());
    long ans = 0;
    for (int i = 2; i < items.size(); i += 3) {
      ans += items.get(i);
    }
    System.out.println(ans);
  }
}
