class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (auto& m : moves) {
      switch (m) {
        case 'U':
          ++y;
          break;
        case 'D':
          --y;
          break;
        case 'R':
          ++x;
          break;
        case 'L':
          --x;
          break;
        default:
          break;
      }
    }

    return x == 0 && y == 0;
  }
};  // 16ms

class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (auto& m : moves) {
      if (m == 'U') {
        ++y;
      } else if (m == 'D') {
        --y;
      } else if (m == 'L') {
        --x;
      } else {
        ++x;
      }
    }

    return x == 0 && y == 0;
  }
};  // 24ms