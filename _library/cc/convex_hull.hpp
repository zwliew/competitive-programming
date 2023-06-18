
void convex_hull(vector<point> &a, bool include_collinear = false) {
  if (a.size() == 1)
    return;

  sort(a.begin(), a.end(),
       [](point a, pt b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); });
  point p1 = a[0], p2 = a.back();
  vector<point> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
      while (up.size() >= 2 &&
             !cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
      while (down.size() >= 2 &&
             !ccw(down[down.size() - 2], down[down.size() - 1], a[i],
                  include_collinear))
        down.pop_back();
      down.push_back(a[i]);
    }
  }

  if (include_collinear && up.size() == a.size()) {
    reverse(a.begin(), a.end());
    return;
  }
  a.clear();
  for (int i = 0; i < (int)up.size(); i++)
    a.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; i--)
    a.push_back(down[i]);
}
