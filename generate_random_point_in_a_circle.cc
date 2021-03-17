class Solution {
  double x;
  double y;
  double r;

 public:
  Solution(double radius, double x_center, double y_center) {
    x = x_center;
    y = y_center;
    r = radius;
  }

  vector<double> randPoint() {
    double dx = 0;
    double dy = 0;

    do {
      dx = (2 * ((double)rand() / RAND_MAX) - 1) * r;
      dy = (2 * ((double)rand() / RAND_MAX) - 1) * r;
    } while (dx * dx + dy * dy > r * r);

    return {x + dx, y + dy};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// Runtime: 84 ms, faster than 92.49%
// Memory Usage: 26.8 MB, less than 98.84%