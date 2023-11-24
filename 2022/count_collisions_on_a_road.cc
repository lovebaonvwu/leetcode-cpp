class Solution {
 public:
  int countCollisions(string directions) {
    int left = 0;
    while (left < directions.size() && directions[left] == 'L') {
      ++left;
    }

    int right = directions.size() - 1;
    while (right >= 0 && directions[right] == 'R') {
      --right;
    }

    int ans = 0;

    for (int i = left; i <= right; ++i) {
      if (directions[i] != 'S') {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 78 ms, faster than 75.00%
// Memory Usage: 16.4 MB, less than 75.00%
// 2022.3.21 at 奥盛大厦

class Solution {
 public:
  int countCollisions(string directions) {
    int left = 0;
    while (left < directions.size() && directions[left] == 'L') {
      ++left;
    }

    int ans = 0;

    for (int i = left, cnt = 0; i < directions.size(); ++i) {
      if (directions[i] == 'R') {
        ++cnt;
      } else {
        ans += directions[i] == 'S' ? cnt : cnt + 1;
        cnt = 0;
      }
    }

    return ans;
  }
};
// Runtime: 101 ms, faster than 25.00%
// Memory Usage: 16.2 MB, less than 75.00%
// 2022.3.21 at 奥盛大厦