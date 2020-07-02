// Point assign, range query Segment Tree
public class SegmentTree {
  int lo, hi;
  SegmentTree left, right;
  int val;

  SegmentTree(final int[] a, final int lo, final int hi) {
    this.lo = lo;
    this.hi = hi;

    if (lo == hi) {
      val = a[lo];
      return;
    }

    final int mid = lo + (hi - lo) / 2;
    left = new SegmentTree(a, lo, mid);
    right = new SegmentTree(a, mid + 1, hi);

    compute();
  }

  void assign(final int idx, final int val) {
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
    // TODO: Implement the compute method
  }
}