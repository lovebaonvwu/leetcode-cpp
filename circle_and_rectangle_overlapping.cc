class Solution {
 public:
  bool checkOverlap(int radius,
                    int x_center,
                    int y_center,
                    int x1,
                    int y1,
                    int x2,
                    int y2) {
    for (int i = x1; i <= x2; ++i) {
      for (int j = y2; j >= y1; --j) {
        if (pow(abs(i - x_center), 2) + pow(abs(j - y_center), 2) <=
            radius * radius) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 1328 ms, faster than 5.32%
// Memory Usage: 6 MB, less than 57.03%

class Solution {
 public:
  bool checkOverlap(int radius,
                    int x_center,
                    int y_center,
                    int x1,
                    int y1,
                    int x2,
                    int y2) {
    int x = max(x1, min(x_center, x2));
    int y = max(y1, min(y_center, y2));

    return pow(x - x_center, 2) + pow(y - y_center, 2) <= pow(radius, 2);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 8.37%