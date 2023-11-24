class Solution {
 public:
  bool isRobotBounded(string instructions) {
    int x = 0;
    int y = 0;
    int dir = 0;

    for (auto i : instructions) {
      if (i == 'G') {
        if (dir == 0) {
          ++y;
        } else if (dir == 1) {
          ++x;
        } else if (dir == 2) {
          --y;
        } else {
          --x;
        }
      } else if (i == 'R') {
        ++dir;
      } else {
        --dir;
      }

      dir &= 0x3;
    }

    return (x == 0 && y == 0) || (dir != 0);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 42.31%