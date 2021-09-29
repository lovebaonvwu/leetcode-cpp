class Solution {
 public:
  int computeArea(int ax1,
                  int ay1,
                  int ax2,
                  int ay2,
                  int bx1,
                  int by1,
                  int bx2,
                  int by2) {
    ax1 += 10000, ay1 += 10000, ax2 += 10000, ay2 += 10000;
    bx1 += 10000, by1 += 10000, bx2 += 10000, by2 += 10000;

    int x1 = max(ax1, bx1), y1 = max(ay1, by1);
    int x2 = min(ax2, bx2), y2 = min(ay2, by2);

    int ans = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

    int overlap = 0;

    if (x1 < x2 && y1 < y2) {
      overlap = (x2 - x1) * (y2 - y1);
    }

    return ans - overlap;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 37.07%
// 2021.9.29 at 奥盛大厦