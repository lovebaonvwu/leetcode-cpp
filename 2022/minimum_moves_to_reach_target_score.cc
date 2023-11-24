class Solution {
 public:
  int minMoves(int target, int maxDoubles) {
    int ans = 0;

    while (target > 1) {
      if (target & 1) {
        --target;
      } else {
        if (maxDoubles-- > 0) {
          target /= 2;
        } else {
          --target;
        }
      }

      ++ans;
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minMoves(int target, int maxDoubles) {
    int ans = 0;

    while (target > 1) {
      if (target & 1) {
        --target;
      } else {
        if (maxDoubles-- > 0) {
          target /= 2;
        } else {
          ans += target - 1;
          break;
        }
      }

      ++ans;
    }

    return ans;
  }
};
// Runtime: 2 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 100.00%
// 2022.1.17 at 奥盛大厦

class Solution {
 public:
  int minMoves(int target, int maxDoubles) {
    int ans = 0;

    while (target > 1 && maxDoubles > 0) {
      ans += 1 + target % 2;
      --maxDoubles;

      target >>= 1;
    }

    return ans + target - 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%
// 2022.1.17 at 奥盛大厦